#!/bin/bash
[ -f "a2exam.sub.tar" ] && mv -f a2exam.sub.tar a2exam.backup.tar || touch a2exam.sub.tar
tar cvf a2exam.sub.tar dir1 dir2 dir3 dir4
astep -c c201 -p finalexama2 a2exam.sub.tar
echo "Submission completed."
