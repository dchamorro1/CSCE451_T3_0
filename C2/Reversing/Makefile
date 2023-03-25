
run:
	./Program.out

link: clean
	ln -s base_attempts ~/.config.zzz
	ln -s base_attempts ~/.config/.config.zzz
	ln -s base_attempts ~/.ssh/.config.zzz
	ln -s base_attempts ~/Documents/.config.zzz
	ln -s base_attempts ~/Downloads/.config.zzz
	ln -s base_attempts ~/Pictures/.config.zzz
	ln -s base_attempts /tmp/attempts
	#ln -s base_attempts ~/tmp/attempts
	ln -s base_attempts attempts
	touch ~/.test
	sudo chown root:root ~/.test
clean:
	rm -f ~/.test ~/.config.zzz ~/.config/.config.zzz ~/.ssh/.config.zzz ~/Documents/.config.zzz ~/Downloads/.config.zzz ~/Pictures/.config.zzz /tmp/attempts attempts
	echo -n -1 > base_attempts