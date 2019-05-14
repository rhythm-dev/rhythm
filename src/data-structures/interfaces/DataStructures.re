module Sequence = {
  type camlArrayCapabilities('a) =
    [< | `ConstantGetFirst | `ConstantGetIndex | `ConstantGetLast] as 'a;

  type camlListCapabilities('a) =
    [< | `ConstantGetFirst | `ConstantAddFirst | `ConstantRemoveFirst] as 'a;

  type dequeCapabilities('a) =
    [<
      | `ConstantGetFirst
      | `ConstantGetLast
      | `ConstantAddFirst
      | `ConstantAddLast
      | `ConstantRemoveFirst
      | `ConstantRemoveLast
    ] as 'a;

  type sequence('el, 'capabilities) =
    | CamlArray(CamlArray.t('el))
      : sequence('el, camlArrayCapabilities('tag))
    | CamlList(CamlList.t('el)): sequence('el, camlListCapabilities('tag))
    | Deque(Deque.t('el)): sequence('el, dequeCapabilities('tag));

  let make = () => Deque(Deque.make());
  let makeCamlArray = () => CamlArray(CamlArray.make());
  let makeCamlList = () => CamlList(CamlList.make());
  let makeDeque = () => Deque(Deque.make());

  type getFirstRequirements('a) = [> | `ConstantGetFirst] as 'a;
  let getFirstExn: sequence('el, getFirstRequirements('capabilities)) => 'el =
    ds => {
      ();
      switch (ds) {
      | CamlArray(ds) => CamlArray.getFirstExn(ds)
      | CamlList(ds) => CamlList.getFirstExn(ds)
      | Deque(ds) => Deque.getFirstExn(ds)
      };
    };

  type getLastRequirements('a) = [> | `ConstantGetLast] as 'a;
  let getLastExn: sequence('el, getLastRequirements('capabilities)) => 'el =
    ds => {
      ();
      switch (ds) {
      | CamlArray(ds) => CamlArray.getLastExn(ds)
      | Deque(ds) => Deque.getLastExn(ds)
      };
    };

  type addFirstRequirements('a) = [> | `ConstantAddFirst] as 'a;
  let addFirst:
    ('el, sequence('el, addFirstRequirements('capabilities))) =>
    sequence('el, 'capabilities) =
    (el, ds) => {
      ();
      switch (ds) {
      | CamlList(ds) => CamlList(CamlList.addFirst(el, ds))
      | Deque(ds) => Deque(Deque.addFirst(el, ds))
      };
    };

  type addLastRequirements('a) = [> | `ConstantAddLast] as 'a;
  let addLast:
    ('el, sequence('el, addLastRequirements('capabilities))) =>
    sequence('el, 'capabilities) =
    (el, ds) => {
      ();
      switch (ds) {
      | Deque(ds) => Deque(Deque.addLast(el, ds))
      };
    };
};
