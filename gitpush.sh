#!/bin/bash

arg="$1"
git add .
git commit -m arg
git push origin master
