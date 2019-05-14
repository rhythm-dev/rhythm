open TestFramework;

/* red orange yellow green blue indigo violet */
module Color = {
  /* Dummy side-effect for testing. */
  let handle: 'a => unit = arg => ();

  /* Primary colors */
  type red('a) = [< | `Red] as 'a;
  type green('a) = [< | `Green] as 'a;
  type blue('a) = [< | `Blue] as 'a;

  /* Compound colors */
  type orange('a) = [< | `Red | `Green] as 'a;
  type purple('a) = [< | `Red | `Blue] as 'a;

  type color('payload, 'tag) =
    | Red('payload): color('payload, red('poly))
    | Green('payload): color('payload, green('poly))
    | Blue('payload): color('payload, blue('poly))
    | Orange('payload): color('payload, orange('poly))
    | Purple('payload): color('payload, purple('poly));

  type handleRedInput('a) = [> | `Red] as 'a;
  let handleRed:
    color('payload, handleRedInput('tag)) => color('payload, 'tag) =
    color => {
      ();
      switch (color) {
      | Red(payload) as color =>
        handle(payload);
        color;
      | Orange(payload) as color =>
        handle(payload);
        color;
      | Purple(payload) as color =>
        handle(payload);
        color;
      };
    };

  type handleGreenInput('a) = [> | `Green] as 'a;
  let handleGreen:
    color('payload, handleGreenInput('tag)) => color('payload, 'tag) =
    color => {
      ();
      switch (color) {
      | Green(payload) as color =>
        handle(payload);
        color;
      | Orange(payload) as color =>
        handle(payload);
        color;
      };
    };
};

describe("Colors", ({test}) => {
  test("testing", ({expect}) => {
    let c = Color.Orange(1);
    let c = Color.handleRed(c);
    /* Why doesn't this work? It loses "orange type" after handling red. */
    /* let c = Color.handleGreen(c); */
    let _ = c;
    let c = Color.Purple(1);
    /* Good. Error like expected. */
    /* let c = Color.handleGreen(c); */
    let c = Color.handleRed(c);
    let _ = c;
    ();
  });
  ();
});
