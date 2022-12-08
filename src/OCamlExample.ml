let ( |> ) x f = f x

let square x = x * x

let prepend x = "Result: " ^ x

let () =
  42
  |> square
  |> string_of_int
  |> prepend
  |> print_endline

