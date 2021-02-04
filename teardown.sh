#!/bin/bash

./clean.sh

ARCHIVE_DIR=$(date "+%Y-%m-%d-%H%M")
mv workspace/ $ARCHIVE_DIR

mv $ARCHIVE_DIR/ archive
