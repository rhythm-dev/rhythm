open TestFramework;
open Rhythm;

describe("DataStructures", ({test}) => {
  test("dummy", ({expect}) => {
    ();
    ();
  });

  test("testing", ({expect}) => {
    module Sequence = DataStructures.Sequence;
    let ds =
      Sequence.makeDeque()
      |> Sequence.addLast(0)
      |> Sequence.addFirst(1)
      |> Sequence.addFirst(2)
      |> Sequence.addLast(1);
    let _ = ds;

    let ds =
      Sequence.makeCamlList()
      |> Sequence.addFirst(0);
    let _ = ds;

    expect.int(2).toBe(2);
  });
});
