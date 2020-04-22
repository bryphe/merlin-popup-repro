/*
 * MerlinDiscovery
 *
 * Helper module for finding Merlin in the current environment
 */

let createMerlinFromPaths =
    (merlinPath: option(string), merlinReasonPath: option(string)) => {
  let additionalPaths =
    switch (merlinReasonPath) {
    | Some(x) =>
      prerr_endline("MerlinDiscovery::createMerlinFromPaths - using ocamlmerlin-reason path:" ++ x);
      [Rench.Path.dirname(x)];
    | None => []
    };

  // Once #13 is fixed, we can always use server!
  //let singleOrServer = Sys.win32 ? Merlin.Single : Merlin.Server;
  let singleOrServer = Merlin.Server;

  switch (merlinPath) {
  | None => None
  | Some(x) => Some(Merlin.init(singleOrServer, x, additionalPaths))
  };
};

let findMerlinInEnvironmentOverride = () => {
  let merlinPath =
    Rench.Environment.getEnvironmentVariable("MLS_MERLIN_PATH");
  let reasonPath =
    Rench.Environment.getEnvironmentVariable("MLS_MERLIN_REASON_PATH");
  createMerlinFromPaths(merlinPath, reasonPath);
};

let getBinaryFromEsySandbox = (cwd, esyPath, binaryName: string) => {
  let whichOrWhere = Sys.win32 ? "where" : "which";

  prerr_endline (" -- cwd: " ++ cwd);
  let where =
    Rench.ChildProcess.spawnSync(
      ~cwd=Some(cwd),
      esyPath,
      [|whichOrWhere, binaryName|],
    );

  switch (where.exitCode) {
  | 0 =>
    where.stdout
    |> String.split_on_char('\n')
    |> List.hd
    |> String.trim
    |> Some
  | _ => None
  };
};

let findMerlinWithEsy = path => {
  let esyPath = Rench.Environment.which("esy");

  switch (esyPath) {
  | Some(esy) =>
    /* There's an esy in the environment... let's see if we can find merlin in the project */
    let p = path;
    let suffix = Sys.win32 ? ".cmd" : "";
    let esy = esy ++ suffix;
    let merlinPath = getBinaryFromEsySandbox(p, esy, "ocamlmerlin");
    let reasonPath = getBinaryFromEsySandbox(p, esy, "ocamlmerlin-reason");
    createMerlinFromPaths(merlinPath, reasonPath);
  | None => None
  };
};

let findMerlinInEnvironment = () => {
  let merlin = Rench.Environment.which("ocamlmerlin");
  let reasonPath = Rench.Environment.which("ocamlmerlin-reason");

  createMerlinFromPaths(merlin, reasonPath);
};

let discover = path => {
  switch (findMerlinInEnvironmentOverride()) {
  | Some(v) => Some(v)
  | None =>
    switch (findMerlinWithEsy(path)) {
    | Some(v) => Some(v)
    | None => findMerlinInEnvironment()
    }
  };
};
