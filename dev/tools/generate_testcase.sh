#!/bin/bash

# Create test1.txt
cat > test1.txt << 'EOF'
4.ox
....
.o..
....
....
EOF

# Create test2.txt
cat > test2.txt << 'EOF'
5.ox
.....
.o.o.
..o..
.o.o.
.....
EOF

# Create test3.txt
cat > test3.txt << 'EOF'
3.ox
...
...
...
EOF

# Create test4.txt
cat > test4.txt << 'EOF'
5#*@
#####
##*##
#####
##*##
#####
EOF

# Create test5.txt
cat > test5.txt << 'EOF'
6.ox
oooooo
o....o
o....o
o....o
o....o
oooooo
EOF

# Create test6.txt
cat > test6.txt << 'EOF'
3.ox
........
...o....
........
EOF

# Create test7.txt
cat > test7.txt << 'EOF'
10.ox
..........
....o.....
..........
.....o....
..........
......o...
..........
.......o..
..........
....o.....
EOF

# Create test8.txt
cat > test8.txt << 'EOF'
4.ox
oooo
oooo
oooo
oooo
EOF

# Create test9.txt
cat > test9.txt << 'EOF'
5.ox
ooooo
ooooo
oo.oo
ooooo
ooooo
EOF

# Create test10.txt
cat > test10.txt << 'EOF'
1.ox
.
EOF

echo "All test files have been created successfully."