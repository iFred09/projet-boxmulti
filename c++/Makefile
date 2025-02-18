##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#  Modifié par Frédéric SRICHANWIT - 2025
#
##########################################
.PHONY: clean clean-all
#
# Nom du programme
#
SERVER = server
CLIENT = client
CLISERV = cliserv

#
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
#
SERVER_SOURCES = main.cpp Base.cpp Film.cpp Groupe.cpp Gestionnaire.cpp tcpserver.cpp ccsocket.cpp
CLIENT_SOURCES = client.cpp ccsocket.cpp
CLISERV_SOURCES = ${SERVER_SOURCES} ${CLIENT_SOURCES} Makefile

#
# Fichiers objets (ne pas modifier sauf si l'extension n'est pas .cpp)
#
SERVER_OBJETS = ${SERVER_SOURCES:%.cpp=%.o}
CLIENT_OBJETS = ${CLIENT_SOURCES:%.cpp=%.o}

#
# Compilateur C++
#
CXX = c++

#
# Options du compilateur C++
#   -g pour debugger, -O optimise, -Wall affiche les erreurs, -I pour les headers
#   -std=c++11 pour C++11
# Exemple: CXXFLAGS= -std=c++11 -Wall -O -I/usr/local/qt/include
#
CXXFLAGS = -std=c++11 -Wall -g

#
# Options de l'editeur de liens
#
LDFLAGS = 

#
# Librairies a utiliser
# Exemple: LDLIBS = -L/usr/local/qt/lib -lqt
#
LDLIBS = 


##########################################
#
# Regles de construction/destruction des .o et de l'executable
# depend-${PROG} sera un fichier contenant les dependances
#
 
all: ${SERVER} ${CLIENT}

run-${SERVER}: ${SERVER}
	./${SERVER}

run-${CLIENT}: ${CLIENT}
	./${CLIENT}

${SERVER}: depend-${SERVER} ${SERVER_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${SERVER_OBJETS} ${LDLIBS}

${CLIENT}: depend-${CLIENT} ${CLIENT_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${CLIENT_OBJETS} ${LDLIBS}

clean:
	-@$(RM) *.o depend-${CLIENT} depend-${SERVER} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) ${CLIENT} ${SERVER} 1>/dev/null 2>&1
  
tar:
	tar cvf ${CLISERV}.tar.gz ${CLISERV_SOURCES}

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de g++ (attention tous les compilateurs n'ont pas cette option)
#
depend-${CLIENT}:
	${CXX} ${CXXFLAGS} -MM ${CLIENT_SOURCES} > depend-${CLIENT}

depend-${SERVER}:
	${CXX} ${CXXFLAGS} -MM ${SERVER_SOURCES} > depend-${SERVER}


###########################################
#
# Regles implicites
#

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<


#############################################
#
# Inclusion du fichier des dependances
#
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),clean-all)
    -include depend-${CLIENT}
    -include depend-${SERVER}
endif
endif