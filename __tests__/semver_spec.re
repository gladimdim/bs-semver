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
        test("#compare", () =>
          expect(Semver.compare("1.2.3", "5.6.3")) |> toBe(-1)
        );
        test("#rcompare", () =>
          expect(Semver.rcompare("1.2.3", "5.6.3")) |> toBe(1)
        );
        test("#version", () =>
          expect(Semver.createSemver("1.3.5")##version) |> toBe("1.3.5")
        );
        test("#major", () =>
          expect(Semver.createSemver("1.3.5")##major) |> toBe(1)
        );
        test("#minor", () =>
          expect(Semver.createSemver("1.3.5")##minor) |> toBe(3)
        );
        test("#patch", () =>
          expect(Semver.createSemver("1.3.5")##patch) |> toBe(5)
        );
        test("#raw", () =>
          expect(Semver.createSemver("1.3.5")##raw) |> toBe("1.3.5")
        );
        test("#build", () =>
          expect(Semver.createSemver("1.3.5-alpha.3.1+1.x.y.3")##build)
          |> toEqual([|"1", "x", "y", "3"|])
        );
        test("#build can be empty", () =>
          expect(Semver.createSemver("1.3.5-alpha.3.1")##build)
          |> toEqual([||])
        );
        test("#prerelease with only strings", () =>
 /* prerelease might also get int, but I test only against strings */
          expect(Semver.createSemver("1.3.5-alpha")##prerelease)
          |> toEqual([|"alpha"|])
        );
	test("#prerelease can be empty", () => 
          expect(Semver.createSemver("1.3.5")##prerelease) |> toEqual([||])
	);
      }
    ),
  );
