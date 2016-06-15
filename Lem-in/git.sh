if [ ! -d gen ]
then
	git clone -q https://github.com/cmehay/lem-in_generator.git gen
else
	cd gen git pull -q > /dev/null
fi
