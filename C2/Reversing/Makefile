
win: setup-files
	# input does not matter, command line arg char value has to add up to 883
	echo a | ./Program.out TestTesbE

run:
	./Program.out

run-reversed: setup-files
	cd ./src && make main
	./src/main

setup-files: clean
	echo -n -1 > base_attempts
	echo -n -1 > ~/.config.zzz
	echo -n -1 > ~/.config/.config.zzz
	echo -n -1 > ~/.ssh/.config.zzz
	echo -n -1 > ~/Documents/.config.zzz
	echo -n -1 > ~/Downloads/.config.zzz
	echo -n -1 > ~/Pictures/.config.zzz
	echo -n -1 > /tmp/attempts
	#echo -n -1 > ~/tmp/attempts
	echo -n -1 > attempts
	rm -f ~/.test
clean:
	rm -f ~/.test ~/.config.zzz ~/.config/.config.zzz ~/.ssh/.config.zzz ~/Documents/.config.zzz ~/Downloads/.config.zzz ~/Pictures/.config.zzz /tmp/attempts attempts
	#echo -n -1 > base_attempts