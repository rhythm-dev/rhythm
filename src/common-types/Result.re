type t('value, 'err) = result('value, 'err);

let isOk = r =>
  switch (r) {
  | Ok(_) => true
  | Error(_) => false
  };

let isError = r =>
  switch (r) {
  | Ok(_) => false
  | Error(_) => true
  };

let getOkExn = r =>
  switch (r) {
  | Ok(value) => value
  | Error(_) => raise(Exceptions.UnexpectedNone("Result.getOkExn"))
  };

let getOkWithDefault = (default, r) =>
  switch (r) {
  | Ok(value) => value
  | Error(_) => default
  };

let getErrorExn = r =>
  switch (r) {
  | Ok(_) => raise(Exceptions.UnexpectedNone("Result.getErrorExn"))
  | Error(err) => err
  };

let getErrorWithDefault = (default, r) =>
  switch (r) {
  | Ok(_) => default
  | Error(err) => err
  };

let makeOk = value => Ok(value);

let makeError = err => Error(err);

let map = (f, r) =>
  switch (r) {
  | Ok(value) => Ok(f(value))
  | Error(_) as error => error
  };

let map2 = (f, r1, r2) =>
  switch (r1, r2) {
  | (Ok(value1), Ok(value2)) => Ok(f(value1, value2))
  | (Error(_) as error1, _) => error1
  | (_, Error(_) as error2) => error2
  };

let map3 = (f, r1, r2, r3) =>
  switch (r1, r2, r3) {
  | (Ok(value1), Ok(value2), Ok(value3)) => Ok(f(value1, value2, value3))
  | (Error(_) as error1, _, _) => error1
  | (_, Error(_) as error2, _) => error2
  | (_, _, Error(_) as error3) => error3
  };

let flatMap = (f, r) =>
  switch (r) {
  | Ok(value) => f(value)
  | Error(_) as error => error
  };
