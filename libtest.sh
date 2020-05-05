exectest() {
  result=$(eval "$1|xargs")
  if [ "$result" != "$2" ]; then
    echo "Error: '$1' respond '$result', but hope is '$2'"
    exit 1
  fi
}
