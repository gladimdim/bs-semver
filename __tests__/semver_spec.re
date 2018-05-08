open Jest;

let () =
  describe(
    "semver",
    ExpectJs.(
      () => {
        test("#patch", () =>
          expect(Semver.patch("2.3.4")) |> toBe(4)
        );
        test("#major", () =>
          expect(Semver.major("2.3.4")) |> toBe(2)
        );
        test("#minor", () =>
          expect(Semver.minor("2.3.4")) |> toBe(3)
        );
        test("#valid", () =>
          expect(
            Semver.valid("2.3.4")
            |> (
              result =>
                switch (result) {
                | Some(v) => v
                | None => raise(Not_found)
                }
            ),
          )
          |> toBe("2.3.4")
        );
        test("#satisfies", () =>
          expect(Semver.satisfies("2.3.4", "< 2.4.0")) |> toBe(true)
        );
        test("#inc", () =>
          expect(
            Semver.inc("2.3.4", Semver.Patch)
            |> (
              result =>
                switch (result) {
                | Some(v) => v
                | None => raise(Not_found)
                }
            ),
          )
          |> toBe("2.3.5")
        );
        test("#clean", () =>
          expect(
            Semver.clean("    =1.5.0    ")
            |> (
              result =>
                switch (result) {
                | Some(v) => v
                | None => raise(Not_found)
                }
            ),
          )
          |> toBe("1.5.0")
        );
        test("#gt", () =>
          expect(Semver.gt("10.5.3", "10.4.0")) |> toBe(true)
        );
        test("#lt", () =>
          expect(Semver.lt("10.5.3", "10.4.0")) |> toBe(false)
        );
        test("#gte", () =>
          expect(Semver.gte("10.5.3", "10.5.3")) |> toBe(true)
        );
        test("#lte", () =>
          expect(Semver.lte("10.5.3", "10.4.0")) |> toBe(false)
        );
        test("#eq", () =>
          expect(Semver.eq("10.5.3", "10.5.3")) |> toBe(true)
        );
        test("#neq", () =>
          expect(Semver.neq("10.5.3", "10.5.3")) |> toBe(false)
        );

      }
    ),
  );
