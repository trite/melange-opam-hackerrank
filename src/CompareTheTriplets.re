// https://www.hackerrank.com/challenges/compare-the-triplets/problem

let (>>) = (f, g, x) => g(f(x));

Readline.readLine(line1 => {
  Readline.readLine(line2 => {
    let parseLine =
      Js.String.split(" ")
      >> Js.Array.map(int_of_string);

    let items1 = line1 |> parseLine;
    let items2 = line2 |> parseLine;

    let (ans1, ans2) = 
        items1
        |> Js.Array.mapi( (item1, i) =>
            compare(item1, items2 |> Array.at(i) |> Option.getOrThrow)
            |> fun
                | -1 => (0,1)
                | 0 => (0,0)
                | 1 => (1,0)
                | _ => failwith("This shouldn't be possible!")
        )
        |> Js.Array.reduce(((ll, lr), (rl, rr)) => (ll + rl, lr + rr), (0, 0));

    let ans1 = string_of_int(ans1);
    let ans2 = string_of_int(ans2);

    Js.log(ans1 ++ " " ++ ans2);

    Readline.close();
  });
});