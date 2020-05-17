type getter = {get: 'a 'b. Recoil__Value.t('a, 'b) => 'a};

type getterAndSetter = {
  get: 'a 'b. Recoil__Value.t('a, 'b) => 'a,
  set: 'a. (Recoil__Value.t('a, Recoil__Value.readWrite), 'a) => unit,
};

type selectorConfig('a) = {
  key: string,
  get: getter => 'a,
};

type selectorWithWriteConfig('a) = {
  key: string,
  get: getter => 'a,
  set: (getterAndSetter, 'a) => unit,
};

type asyncSelectorConfig('a) = {
  key: string,
  get: getter => Js.Promise.t('a),
};

[@bs.module "recoil"]
external selectorWithWrite:
  selectorWithWriteConfig('a) => Recoil__Value.t('a, Recoil__Value.readWrite) =
  "selector";

[@bs.module "recoil"]
external selector:
  selectorConfig('a) => Recoil__Value.t('a, Recoil__Value.readOnly) =
  "selector";

[@bs.module "recoil"]
external asyncSelector:
  asyncSelectorConfig('a) => Recoil__Value.t('a, Recoil__Value.readOnly) =
  "selector";
