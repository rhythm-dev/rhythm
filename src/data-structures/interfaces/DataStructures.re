let unreachable = (dataStructure, method) =>
  failwith(
    dataStructure
    ++ " should not be able to be used with "
    ++ method
    ++ ". How did this happen??",
  );

module Sequence = {
  open Feature;

  type t('el, 'getFirst, 'getLast, 'addFirst, 'addLast) =
    | CamlArray(CamlArray.t('el))
      : t(
          'el,
          getFirst(fast),
          getLast(fast),
          addFirst(slow),
          addLast(slow),
        )
    | CamlList(CamlList.t('el))
      : t(
          'el,
          getFirst(fast),
          getLast(slow),
          addFirst(fast),
          addLast(slow),
        )
    | Deque(Deque.t('el))
      : t(
          'el,
          getFirst(fast),
          getLast(fast),
          addFirst(fast),
          addLast(fast),
        );

  let make = () => Deque(Deque.make());
  let makeCamlArray = () => CamlArray(CamlArray.make());
  let makeCamlList = () => CamlList(CamlList.make());
  let makeDeque = () => Deque(Deque.make());

  let getFirstExn:
    type anyGetFirst anyGetLast anyAddFirst anyAddLast.
      t('el, getFirst(fast), anyGetLast, anyAddFirst, anyAddLast) => 'el =
    ds => {
      ();
      switch (ds) {
      | CamlArray(ds) => CamlArray.getFirstExn(ds)
      | CamlList(ds) => CamlList.getFirstExn(ds)
      | Deque(ds) => Deque.getFirstExn(ds)
      };
    };

  let getLastExn:
    type anyGetFirst anyGetLast anyAddFirst anyAddLast.
      t('el, anyGetFirst, getLast(fast), anyAddFirst, anyAddLast) => 'el =
    ds => {
      ();
      switch (ds) {
      | CamlArray(ds) => CamlArray.getLastExn(ds)
      | CamlList(ds) => unreachable("CamlList", "getLastExn")
      | Deque(ds) => Deque.getLastExn(ds)
      };
    };

  let addFirst:
    type anyGetFirst anyGetLast anyAddFirst anyAddLast.
      ('el, t('el, anyGetFirst, anyGetLast, addFirst(fast), anyAddLast)) =>
      t('el, anyGetFirst, anyGetLast, addFirst(fast), anyAddLast) =
    (el, ds) => {
      ();
      switch (ds) {
      | CamlArray(ds) => unreachable("CamlArray", "addFirst")
      | CamlList(ds) => CamlList(CamlList.addFirst(el, ds))
      | Deque(ds) => Deque(Deque.addFirst(el, ds))
      };
    };

  let addLast:
    type anyGetFirst anyGetLast anyAddFirst anyAddLast.
      ('el, t('el, anyGetFirst, anyGetLast, anyAddFirst, addLast(fast))) =>
      t('el, anyGetFirst, anyGetLast, anyAddFirst, addLast(fast)) =
    (el, ds) => {
      ();
      switch (ds) {
      | CamlArray(ds) => unreachable("CamlArray", "addLast")
      | CamlList(ds) => unreachable("CamlList", "addLast")
      | Deque(ds) => Deque(Deque.addFirst(el, ds))
      };
    };
};
