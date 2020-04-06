#!/bin/bash

#/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
#brew install sendemail

sendEmail -f maxime.craipeau@gmail.com -t $1 -s smtp.gmail.com:587 -xu maxime.craipeau@gmail.com -xp po2bnv6DFRg -u "CodeNames Mail" -m "Voici votre carte. Soyez discret, vous êtes dans l'équipe bleu" -a $3 &> /dev/null
sendEmail -f maxime.craipeau@gmail.com -t $2 -s smtp.gmail.com:587 -xu maxime.craipeau@gmail.com -xp po2bnv6DFRg -u "CodeNames Mail" -m "Voici votre carte. Soyez discret, vous êtes dans l'équipe rouge" -a $3 &> /dev/null
