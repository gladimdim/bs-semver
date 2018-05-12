# v0.3.0

* Introduced Semver.createSemver function, which creates Semver JS object.

JavaScript version:
```js
const a = new Semver("0.3.4");
```

ReasonML:
```
let a = Semver.createSemver("0.3.4");
```

* Removed semver npm package from dependencies.
* Created tests for new bindings

