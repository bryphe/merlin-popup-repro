/*
 *
 */
 
let test = () => {
    open Ppx_let_syntax_result;
    let%bind _num = Error("hey");
    _num;
};

