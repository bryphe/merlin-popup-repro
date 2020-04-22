[![Build Status](https://bryphe.visualstudio.com/merlin-language-server/_apis/build/status/bryphe.merlin-language-server?branchName=master)](https://bryphe.visualstudio.com/merlin-language-server/_build/latest?definitionId=16?branchName=master)

# merlin-language-server
### Simple LSP protocol wrapper for [`merlin`](https://github.com/ocaml/merlin), written in [reason](https://reasonml.github.io/)

:warning: Alpha quality

### Overview

`merlin-language-server` is a thin wrapper over the excellent [`merlin`](https://github.com/ocaml/merlin) tooling - implementing the LSP protocol on-top of [`merlin`'s protocol](https://github.com/ocaml/merlin/blob/master/doc/dev/PROTOCOL.md). 

As with `ocaml-language-server`, this is not intended as a replacement for any existing Reason / OCaml tooling, but to make it more accessible across editors.

### Why?
# NOTES:

- Set MERLIN_LOG environment variable to a file
- Run `esy x TestPpxParsing.exe`

Observations:
- In some shells, there is no 'flashing window'. But in some cases, I can reproduce it (like running from the Onivim terminal):


- Using the proposed fix, there is no flashing window, but there is an error message

```
29 items in path, 29 after deduplication
# 27.11 Pparse - apply_rewriter
running "D:\\merlin-language-server\\_build/default/.ppx/dd492af6ac3d011a895e93e95aa5420a/ppx.exe --as-ppx --cookie \"library-name=\\\"Protocol\\\"\"" from directory "D:\\merlin-language-server\\src\\Protocol"
# 27.16 Pparse - report_error
Error while running external preprocessor. Command line: D:\merlin-language-server\_build/default/.ppx/dd492af6ac3d011a895e93e95aa5420a/ppx.exe --as-ppx --cookie "library-name=\"Protocol\"" %merlin_fn_in% %merlin_fn_out% 1>&2
```
