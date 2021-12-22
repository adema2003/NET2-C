#! /bin/bash


echo "De huidige directory is"
pwd
echo "Voer de directory van de files in: "
read sourcedir

echo "Wil je de foto's sorteren op maand of op week?(maand/week)"
read datum

cd $sourcedir

if [ "$datum" == "maand" ]; then
	echo "Je hebt voor maand gekozen, de foto's worden nu op maand gesorteerd"
	for i in *.jpg
	do
	  date=$(date +%m -r "$i");
	  _DATES+=($date);
	  FILES+=($i);
	done

	DATES=$(printf "%s\n" "${_DATES[@]}" | sort -u);
	for date in ${DATES[@]}; do
	  if [ ! -d "$date" ]; then
	    mkdir "$date"
	  fi
	done

	for i in  ${FILES[@]}; do
	  dest=$(date +%m -r "$i")
	  cp -r -p $i "$dest/$i"
	  hash=$(sudo md5sum "$i" | cut -d " " -f 1)
	done
	for i in $dest/*; do
		newhash=$(sudo md5sum "$i" | cut -d " " -f 1)

	done
	if [[ "$hash" == "$newhash" ]]; then
		echo "De foto's zijn met succes gekopieerd!"
		sleep 1
		echo " "
		echo "De oude foto's worden verwijderd." 
		rm -v *
	else
		echo "Er is iets fout gegaan. Probeer het opnieuw"
	fi
	echo "De operatie is klaar"
elif [ "$datum" == "week" ]; then
	echo "Je hebt voor week gekozen, de foto's worden nu op weeknummer gesorteerd."
	for i in *.jpg
	do
	  date=$(date +%U -r "$i");
	  _DATES+=($date);
	  FILES+=($i);
	done

	DATES=$(printf "%s\n" "${_DATES[@]}" | sort -u);
	for date in ${DATES[@]}; do
	  if [ ! -d "$date" ]; then
	    mkdir "$date"
	  fi
	done

	for i in  ${FILES[@]}; do
	  dest=$(date +%U -r "$i")
	  cp -r -p $i "$dest/$i"
	  hash=$(sudo md5sum "$i" | cut -d " " -f 1)
	done
		for i in $dest/*; do
		newhash=$(sudo md5sum "$i" | cut -d " " -f 1)

	done
	if [[ "$hash" == "$newhash" ]]; then
		echo "De foto's zijn met succes gekopieerd!"
		sleep 1
		echo " "
		echo "De oude foto's worden verwijderd." 
		rm -v *
	else
		echo "Er is iets fout gegaan. Probeer het opnieuw"
	fi
	echo "De operatie is klaar"
else
	echo "Er is een fout opgetreden. Probeer het opnieuw"
fi