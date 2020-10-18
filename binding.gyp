{
  "targets": [
    {
      "target_name": "mkdir-native",
      "cflags_cc": [ "-fexceptions -std=gnu++17" ],
      "sources": [ "src/mkdir.cpp", "src/addon.cpp" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
      'xcode_settings': {
        'MACOSX_DEPLOYMENT_TARGET':
          '10.15',
        'CLANG_CXX_LANGUAGE_STANDARD':
          'gnu++17',
        'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',
        'OTHER_CFLAGS': [
          "-fcxx-exceptions",
          '-Wno-unused-result'
        ]
      }
    }
  ]
}