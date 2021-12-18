#!/bin/bash
# atom.io fix on macos
#   for errors like: 
#
#     git clone --recursive ... exited with code 
#     128 stdout: stderr: Cloning into ... fatal:
#     protocol error: bad line length 2
#
#     bogus format in GIT_CONFIG_PARAMETERS

if [[ ! -L "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/bin/git" ]]; then
  mv "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/bin/git" "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/bin/git.bak" 
  ln -s /opt/homebrew/bin/git "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/bin/git"
fi

if [[ ! -L "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/libexec/git-core/git" ]]; then
  mv "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/libexec/git-core/git" "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/libexec/git-core/git.bak"
  ln -s /opt/homebrew/bin/git "/Applications/Atom.app/Contents/Resources/app.asar.unpacked/node_modules/dugite/git/libexec/git-core/git"
fi
