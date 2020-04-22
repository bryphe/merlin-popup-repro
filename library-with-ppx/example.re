/*
 * Example.re
 */
 
let test = () => {
    open Ppx_let_syntax_result;
    let%bind _err = Error("hey");
    _err;
};

