# bs-semver

Bindings to the NPM semver package [https://www.npmjs.com/package/semver]

**Note: still WIP** 

## Installation
```sh
npm install --save @gladimdim/bs-semver
yarn add @gladimdim/bs-semver --save
```
Then add `@gladimdim/bs-semver` to `bs-dependencies` in your `bsconfig.json`:
```js
{
  ...
  "bs-dependencies": ["@gladimdim/bs-semver"]
}
```

# Build

```
npm run build
```

# Watch

```
npm run watch
```

# What is covered
The following functions are covered:
* gt
* gte
* lt
* lte
* eq
* neq
* clean
* valid
* satisfies
* cmp
* compare
* rcompare
* diff
* inc
* patch
* major
* minor

# Notes on nullable return type
Some functions in semver might return null as a valid result. Documentation for semver does not state, which functions return null as a valid value.
So I had to check all of these bindings manually.

For example, in JS following code returns null: 
```js
semver.valid("1.5.1a") ; // null
```

In these bindings, this nullable return type is converted to Option via Js.Nullable.toOption.

So, in Reason you can do like this:
```
semver.valid("1.5.1a") |> result =>
    switch result {
        | Some(v) => v /*string with valid semver version*/
	| None => /* handle case, when input into valid call contained invalid semver function */
    }
```
