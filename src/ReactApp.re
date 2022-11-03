module App = {
  // This sample forces an import of Belt.*, so that CI builds can ensure that
  // Melange has been installed correctly for JS bundlers to be able to find it.
  [@react.component]
  let make = () =>
    // This fails, I think because it's the wrong kind of List? (std vs Relude)
    // ["Hello world!", "This is React!"]
    // |> List.map(greeting => <h1> {greeting |> React.string} </h1>)
    [|"Hello world!", "This is React!"|]
    |> Array.map(greeting => <h1> {greeting |> React.string} </h1>)
    |> React.array;
    // ->Belt.List.map(greeting => <h1> greeting->React.string </h1>)
    // ->Belt.List.toArray
    // ->React.array;
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
