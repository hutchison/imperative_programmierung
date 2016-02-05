# Aufgabe 1

In der Vorlesung haben Sie gelernt, dass ein C Programm durch Aufrufen der
Funktion main gestartet wird und dass der Rückgabewert dieser Funktion vom
Betriebssystem als Ergebnisstatus verwendet wird.

Wie können Sie auf den Laborrechnern in der Kommandozeile auf den Ergebnisstatus
eines Programms zugreifen? Wie geht das bei Ihrem eigenen Rechner?

# Lösung

Sowohl auf den Laborrechnern als auch auf dem eigenen Rechner wird der
Rückgabewert des letzten Befehls in der Shellvariable $? gespeichert. Diesen
kann man mit echo $? ausgeben.

Unter Windows ist dieser Wert in der Umgebungsvariable %errorlevel% gespeichert,
sodass man diesen mit echo %errorlevel% ausgeben kann.
