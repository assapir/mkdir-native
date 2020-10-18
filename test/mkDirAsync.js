const assert = require('assert')
const fs = require('fs')
const mkdir = require('../index')

const test = () => {
  mkdir('this/app/a/b', (err, msg) => {
    if (err) throw err
    assert.ok(fs.statSync('this/app/a/b'))
  })
}

test()
