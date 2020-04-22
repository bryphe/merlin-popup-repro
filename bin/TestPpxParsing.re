open Util;

let get_some =
  fun
  | Some(v) => v
  | None => failwith("None");

let merlin = MerlinDiscovery.discover(Sys.getcwd()) |> get_some;

prerr_endline("Found merlin: " ++ Merlin.(merlin.merlinPath));

let additionalPaths = Merlin.(merlin.additionalPaths);
additionalPaths |> List.iter(prerr_endline);

let testFileContents = 
{|
let test = () => {
    open Ppx_let_syntax_result;
    let%bind _err = Error("hey");
    _err;
};
|};

for (_ in 1 to 10) {
  let res =
    Merlin.getTypeEnclosing(
      merlin,
      Merlin.Position.{line: 1, col: 1},
      "library-with-ppx/example.re",
      testFileContents,
    );

  switch (res) {
  | Ok(_) => prerr_endline("Call was successful.")
  | Error(msg) => prerr_endline("ERROR: " ++ msg)
  };
  Unix.sleepf(1.0);
};
