#!/bin/bash

repo_basename=nerd-golf-tracker
repo="$HOME/svn/$repo_basename"
initial_sources=/tmp/it-agile-nerd-golf-tracker.tar.gz
workspace="$HOME/integration_space/$repo_basename"

# Init repo
rm -rf "$repo"
mkdir -p "$repo"
svnadmin create "$repo"
echo "[general]" > "$repo/conf/svnserve.conf"
echo "anon-access = write" >> "$repo/conf/svnserve.conf"


# Setup dir for importing sources
rm -rf "$workspace"
mkdir -p "$workspace"
cd "$workspace"


# Import initial sources
wget --output-document="$initial_sources" --no-check-certificate https://github.com/it-agile/nerd-golf-tracker-c/tarball/master
tar -xzf "$initial_sources" --strip-components=1

svn import "$workspace" "file://$repo" -m "Initial commit"


# Setup empty integration space
rm -rf "$workspace"
mkdir -p "$workspace"
cd "$workspace"
cd ..

svn checkout "file://$repo"


# Import ignore settings
cd "$workspace"
svn propset svn:ignore -F .svnignore .
svn rm .svnignore

cd "$workspace"
svn ci -m "Ignore build and IDE artifacts"

