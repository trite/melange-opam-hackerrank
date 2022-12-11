// Function composition
let (>>) = (f, g, x) => g(f(x));

// List cons operator
let (^:) = (item, lst) => [item, ...lst];

// Sum an integer array
let sum = Js.Array.reduce((+), 0);

// Produce a list of [x..limit] which is inclusive of `x` and exclusive of `limit`
let rec range = (x, limit) =>
    x >= limit
    ? []
    : x ^: range(x+1, limit);

// Produce an array of [x..limit] which is inclusive of `x` and exclusive of `limit`
let rangeArr = (x, limit) =>
    range(x, limit)
    |> Js.List.toVector;