type t('value) = option('value);

let isSome = o =>
  switch (o) {
  | Some(_) => true
  | None => false
  };

let isNone = o =>
  switch (o) {
  | Some(_) => false
  | None => true
  };

let getWithDefault = (default, o) =>
  switch (o) {
  | Some(value) => value
  | None => default
  };

let getExn = o =>
  switch (o) {
  | Some(value) => value
  | None => raise(Exceptions.UnexpectedNone("Option.getValueExn"))
  };

let makeNone = _ => None;

let makeSome = value => Some(value);

let map = (f, o) =>
  switch (o) {
  | Some(value) => Some(f(value))
  | None => None
  };

let map2 = (f, o1, o2) =>
  switch (o1, o2) {
  | (Some(value1), Some(value2)) => Some(f(value1, value2))
  | _ => None
  };

let map3 = (f, o1, o2, o3) =>
  switch (o1, o2, o3) {
  | (Some(value1), Some(value2), Some(value3)) =>
    Some(f(value1, value2, value3))
  | _ => None
  };

let flatMap = (f, o) =>
  switch (o) {
  | Some(value) => f(value)
  | None => None
  };

module Infix = {
  let (|?:) = (o, default) =>
    switch (o) {
    | Some(value) => value
    | None => default
    };

  let (>>|) = (opt, fn) =>
    switch (opt) {
    | Some(value) => Some(fn(value))
    | None => None
    };

  let (>>=) = (opt, fn) =>
    switch (opt) {
    | Some(value) => fn(value)
    | None => None
    };
};
