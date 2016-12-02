#!/bin/bash

new_date=$(date)

ssh bbb_usb <<EOF # we want expansion of new_date..
#!/bin/bash

echo "This is BBB speaking, trying to set date to: $new_date"

sudo hwclock --set --utc --date "$new_date"
sudo hwclock --systz
sudo hwclock --hctosys

EOF

