open Jest;

let () = describe("semver", ExpectJs.(
  () => {
  test("#patch", () => expect(Semver.patch("2.3.4")) |> toBe(4));
  test("#major", () => expect(Semver.major("2.3.4")) |> toBe(2));
  test("#minor", () => expect(Semver.minor("2.3.4")) |> toBe(3));
  test("#valid", () => expect(
    Semver.valid("2.3.4") |> (result) => 
      switch result {
      | Some(v) => v
      | None => raise(Not_found)
     }
  ) |> toBe("2.3.4"));
  test("#satisfies", () => expect(Semver.satisfies("2.3.4", "< 2.4.0")) |> toBe(true));
  test("#inc", () => expect(
    Semver.inc("2.3.4", Semver.Patch) |> result =>
      switch result {
      | Some(v) => v
      | None => raise(Not_found)
    }) |> toBe("2.3.5"));
  }));
