{
  "targets": [
    {
      "target_name": "mkdir-native",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions -std=c++17" ],
      "sources": [ "src/mkdir.cpp", "src/addon.cpp" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'xcode_settings': {
        'MACOSX_DEPLOYMENT_TARGET':
          '10.15',
        'CLANG_CXX_LANGUAGE_STANDARD':
          'c++17',
        'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
      }
    }
  ]
}