#!/usr/bin/env bash
KICKSTARTER_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source "$KICKSTARTER_ROOT/conf/conf.sh.dist"

if [ -f "$KICKSTARTER_ROOT/conf/conf.sh" ]; then
    source "$KICKSTARTER_ROOT/conf/conf.sh"
fi
