# NOTES:

- Set MERLIN_LOG environment variable to a file
- Run `esy x TestPpxParsing.exe`

> The [procmon](https://docs.microsoft.com/en-us/sysinternals/downloads/procmon) tool can be used along with these instructions to query short-lived processes: https://www.winhelponline.com/blog/procmon-track-process-creation-exit-time/

Observations:
- In some shells, there is no 'flashing window'. But in some cases, I can reproduce it (like running from the Onivim terminal).
- Using the proposed fix, there is no flashing window, but there is an error message
- I do not observe any 'flashing windows' when running via the `ocaml-lsp` server.

```
29 items in path, 29 after deduplication
# 27.11 Pparse - apply_rewriter
running "D:\\merlin-language-server\\_build/default/.ppx/dd492af6ac3d011a895e93e95aa5420a/ppx.exe --as-ppx --cookie \"library-name=\\\"Protocol\\\"\"" from directory "D:\\merlin-language-server\\src\\Protocol"
# 27.16 Pparse - report_error
Error while running external preprocessor. Command line: D:\merlin-language-server\_build/default/.ppx/dd492af6ac3d011a895e93e95aa5420a/ppx.exe --as-ppx --cookie "library-name=\"Protocol\"" %merlin_fn_in% %merlin_fn_out% 1>&2
```
