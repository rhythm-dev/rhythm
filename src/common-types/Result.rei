type t('value, 'err) = result('value, 'err);

let flatMap: ('a => t('b, 'err), t('a, 'err)) => t('b, 'err);

let getOkExn: t('value, 'err) => 'value;
let getOkWithDefault: ('value, t('value, 'err)) => 'value;

let getErrorExn: t('value, 'err) => 'err;
let getErrorWithDefault: ('err, t('value, 'err)) => 'err;

let isError: t('value, 'err) => bool;
let isOk: t('value, 'err) => bool;

let makeError: 'err => t('value, 'err);
let makeOk: 'value => t('value, 'err);

let map: ('a => 'b, t('a, 'err)) => t('b, 'err);
let map2: (('a, 'b) => 'c, t('a, 'err), t('b, 'err)) => t('c, 'err);
let map3:
  (('a, 'b, 'c) => 'd, t('a, 'err), t('b, 'err), t('c, 'err)) =>
  t('d, 'err);
