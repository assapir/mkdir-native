const assert = require('assert')
const fs = require('fs')
const mkdir = require('../index')

const test = () => {
  mkdir('this', (err, msg) => {
    if (err) throw err
    assert.ok(fs.statSync('this'))
  })
}

test()
