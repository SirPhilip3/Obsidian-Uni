---
creation: 2024-10-01T09:09:00
publish: true
---
Nei network moderni non viene usato il [[Bit Stuffing]] , questo è rimpiazzato da un *preambolo* più lungo , questo è usato da *ricevitore* per rilevare l'inizio del [[Frame]] , consente la presenza di errori ma è lungo abbastanza per fare in modo che sia impossibile rilevarlo per sbaglio 

All'interno dell'*header* del [[Frame]] avremo anche la dimensione del frame , in questo modo non necessitiamo di un *marker* per indicare la fine del [[Frame]]
