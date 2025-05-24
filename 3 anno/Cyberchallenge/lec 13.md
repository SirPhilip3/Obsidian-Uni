Web session security 

sessione server side -> id -> info nel server
client side -> info nel cookie 

session hijacking -> se ho cookie impersonaficazione 

proteggere i cookie > js -> document.cookie key value pairs 

httponly -> js non può accedere al cookie

secure cookies -> only https -> non viene mai inviato in http

session fixation
cross site request forgery

flask client side sessions 

SOP -> script da url diversi non condividono storage -> isola domini diversi

Origin : schema + hostname + port 

relaxed sop -> cookie si inviano solo se hostname == -> se hanno schema diversa -> cookie vengono comunque inviati 

WebStorage -> pierfect sop , sent on demand

content inclusion -> non protetto da sop -> ex carico uno script da un altro sito , questo viene eseguito come se fossi io ad eseguirlo

---
CROSS SITE SCRIPTING

->caricato nell'origin del target e eseguito come se fosse il target 

dove ho un input 

-> se un input viene interpretato come js 

in php echo -> usato come html da renderizzare ->usando tag \<script> -> script può leggere tutti i cookie -> te li mandi e hai impersonato 

httponly -> nei cookie -> mitigation -> lo script non può leggerlo 

richieste da js inviano comunque il cookie 

reflected -> script non viene salvato
presistent -> script rimane -> in un commento mette html -> metti script
server-side 
client-side -> codice eseguito dal broswer -> nella query specifico un parametro che può essere incluso in un el html  

break in > consumare il rimanente ex -> `background-color = $input >` , `$input = red><script><script><img=` img per chiuder >

defense -> output encoding -> prima di renderizzare -> encoding `&lt; &gt;` 

document.innertext -> mai interpretato come uno script 

sanitize input -> difficile da fare 

CSRF -> invia html che fa richiesta nel broswer della vittima -> usa cookie originale e verranno inviati lo stesso

def :
+ autenticazione non solo con cookie 
+ SameSite attribure -> non supportato da tutti

nelle http header referrere -> url da dove parte la richiesta -> settato dal broswer non può essere modificato da js -> non sempre incluso

secret tockens -> attaccante non può leggere o scrivere nel dom -> form possiamo mettere un input hidden con un tocken , server genera un token -> lo invia all'utente e lo usa nel form 

double submit -> token nel cookie -> secure ma non httponly

samesite attribute :
+ strict = tutte le richieste http 
+ lax 

