[@bs.module "semver"] [@bs.val] external clean : string => string = "clean";

let clean = a => clean(a);


/***** COMPARISON START *****/
[@bs.module "semver"] [@bs.val] external gt : (string, string) => bool = "gt";

let gt = (a, b) => gt(a, b);

[@bs.module "semver"] [@bs.val]
external gte : (string, string) => bool = "gte";

let gte = (a, b) => gte(a, b);

[@bs.module "semver"] [@bs.val] external lt : (string, string) => bool = "lt";

let lt = (a, b) => lt(a, b);

[@bs.module "semver"] [@bs.val]
external lte : (string, string) => bool = "lte";

let lte = (a, b) => lte(a, b);

[@bs.module "semver"] [@bs.val] external eq : (string, string) => bool = "eq";

let eq = (a, b) => eq(a, b);

[@bs.module "semver"] [@bs.val]
external neq : (string, string) => bool = "neq";

let neq = (a, b) => neq(a, b);

type comparator =
  | LooseEqual
  | LooseNotEqual
  | Equal
  | Empty
  | NotEqual
  | Gt
  | Gte
  | Lt
  | Lte;

let comparatorToString = comparator : string =>
  switch (comparator) {
  | LooseEqual => "=="
  | LooseNotEqual => "!=="
  | Equal => "==="
  | Empty => ""
  | NotEqual => "!=="
  | Gt => ">"
  | Gte => ">="
  | Lt => "<"
  | Lte => "<="
  };

[@bs.module "semver"] [@bs.val]
external cmp : (string, string, string) => bool = "cmp";

let cmp = (a: string, c: comparator, b: string) =>
  cmp(a, c |> comparatorToString, b);

[@bs.module "semver"] [@bs.val]
external compare : (string, string) => int = "compare";

let compare = (a, b) => compare(a, b);

[@bs.module "semver"] [@bs.val]
external rcompare : (string, string) => int = "rcompare";

let rcompare = (a, b) => rcompare(a, b);

type tRelease =
  | Major
  | Minor
  | Patch
  | Premajor
  | Preminor
  | Prepatch;

type tDiff = tRelease;

type tAllDiffs = option(tDiff);

let diffStringToDiff = (input: Js.Nullable.t(string)) => {
  Js.log(input);
  Js.Nullable.toOption(input)
  |> (
    opt =>
      switch (opt) {
      | None => None
      | Some(v) =>
        switch (v) {
        | "major" => Some(Major)
        | "minor" => Some(Minor)
        | "patch" => Some(Patch)
        | "prepatch" => Some(Prepatch)
        | "premajor" => Some(Premajor)
        | "preminor" => Some(Preminor)
        | _ => raise(Not_found)
        }
      }
  );
};

let diffToDiffString = (input: tRelease) =>
  switch (input) {
  | Major => "major"
  | Minor => "minor"
  | Patch => "patch"
  | Premajor => "premajor"
  | Preminor => "preminor"
  | Prepatch => "prepatch"
  };

[@bs.module "semver"] [@bs.val]
external diff : (string, string) => Js.Nullable.t(string) = "diff";

let diff = (a, b) => diff(a, b) |> diffStringToDiff;


/***** FUNCTIONS *****/
[@bs.module "semver"] [@bs.val]
external valid : string => Js.nullable(string) = "valid";

let valid = v => valid(v) |> Js.Nullable.toOption;

[@bs.module "semver"] [@bs.val]
external inc : (string, string) => Js.nullable(string) = "inc";

let inc = (v, release) =>
  inc(v, release |> diffToDiffString) |> Js.Nullable.toOption;

[@bs.module "semver"] [@bs.val] external coerce : string => string = "coerce";

let coerce = a => coerce(a);

[@bs.module "semver"] [@bs.val] external patch : string => int = "patch";

let patch = v => patch(v);

[@bs.module "semver"] [@bs.val] external minor : string => int = "minor";

let minor = v => minor(v);

[@bs.module "semver"] [@bs.val] external major : string => int = "major";

let major = v => major(v);


/***** RANGES *****/
[@bs.module "semver"] [@bs.val]
external satisfies : (string, string) => bool = "satisfies";

let satisfies = (a, b) => satisfies(a, b);
