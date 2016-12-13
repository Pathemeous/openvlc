#!/bin/bash

new_date=$(date)

if [ -z "$1"]; then
  printf "Please call with host, ex:\n$0 bbb1\n"
  exit
fi

ssh $1 <<EOF # we want expansion of new_date..
#!/bin/bash

echo "This is BBB speaking, trying to set date to: $new_date"

sudo hwclock --set --utc --date "$new_date"
sudo hwclock --systz
sudo hwclock --hctosys

EOF

