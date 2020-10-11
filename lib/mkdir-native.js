const addon = require('bindings')('mkdir-native')
const escape = require('js-string-escape')

module.exports = function (path, cb) {
  return addon.mkDirAsync(escape(path), cb)
}
