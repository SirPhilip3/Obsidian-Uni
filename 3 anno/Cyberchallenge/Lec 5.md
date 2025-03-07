---
~
---
Web security 

vuln lato server 

host > disc che server utilizzare

server side req forgery

path trasversal -> in an open 

.. -> con path normalization -> in linux torna idietro 
per scoprire se c'è torna indietro tante voltè in modo di arrivare alla root > vedi se risci a trovare etc/passwd -> accessibile da tutti 

plain -> controllo completo del percorso
append -> input subito dopo > può solo leggere file -> comunque posso tornare indietro con .. 
prepend -> posso solo mettermi prima -> posso vedere solo file che terminano con un certa stringa

se accettano degli url -> file::// -> su una query

middle 

prevenzione -> potrei fare blacklist -> aggirare -> open /dev /sd -> tutti i file apert > questo in realtà è un link a /proc/self/fd -> se uso ../ per tornare indetro da dev/sd lo faccio su /proc etcc 
più ez fai whitelist 

normalizzazione dei percorsi -> fai percorso assoluto da input 
chroots -> path d'entrata diventa la "root" -> non posso tonare indietro

server side request forgery

utente può controllare una richiesta web 

se server fa la richiesta web , se la richiesta avviene dal server stesso su parti protette > potrebbe far accedere , ex loopback 

blind ssrf > don't see the out -> time based fast = reject 

solution > whitelist 
se fai backlisting -> molti modi per scrivere localhost

dmz -> ambiente isolato dal resto dei server 

code injections
php -> system call una funzione sull'os ; -> exec secodo comando
\n && || 

command sob -> $(command) 

subprocess.run() -> runna comando > shell=true -> usa una shell 


