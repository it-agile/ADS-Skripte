#!/bin/bash

repo_basename=nerd-golf-tracker
repo="$HOME/git/$repo_basename.git"
initial_sources=/tmp/it-agile-nerd-golf-tracker.tar.gz
integration_space="$HOME/integration_space/$repo_basename"

# Setup original repo
rm -rf "$repo"
mkdir -p "$repo"
cd "$repo"
git --bare init --shared=all

# Setup empty integration space
rm -rf "$integration_space"
git clone "$repo" "$integration_space"
cd "$integration_space"

# Setup initial sources
wget --output-document="$initial_sources" --no-check-certificate https://github.com/it-agile/nerd-golf-tracker/tarball/master
tar xaf "$initial_sources" --strip-components=1
git add --all
git commit -am "Init"
git push origin master
