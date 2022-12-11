let (|>) = (x, f) => f(x);

let square = x => x * x;

let prepend = x => "Result: " ++ x;

42
|> square
|> string_of_int
|> prepend
|> Js.log;

// let test = (x: list(list(string))) =>
//   x |> List.map(List.reverse);
