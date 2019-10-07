# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 09:25:34 by patrisor          #+#    #+#              #
#    Updated: 2019/10/07 10:03:50 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys,os,datetime,time

def die(reason):
    print(reason)
    return -1

def push():
    if len(sys.argv) != 2:
        exit(die("usage: python3 push.py [commit message]"))
    f = open("README.md", "a+") 
    ts = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S')
    f.write("\n### " + ts + "\n" + sys.argv[1] + "\n")
    os.system("git add -u; git reset -- " + sys.argv[0] + "; git commit -m '" + 
            sys.argv[1] + "'; git push")
    f.close()

push()
