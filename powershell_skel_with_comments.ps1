# Description:    Gibt das Brutto eines angegebenen Nettos des jeweiligen Landes zurück.
#
# Autor:          Julian Reith
# E-Mail:         julianreith@gmx.de
# Version:        1.0
# Last Modified:  2019-12-03

function Get-Brutto{                                                # function = definiert eine Funktion
    <#                                                              # Damit Get-Help für diese Funktion funktioniert
    .SYNOPSIS                                                       # Einleitung
    Brutto berechnen
    .DESCRIPTION                                                    # Beschreibung
    Dieses Cmdlet ermittelt aus einem Nettopreis den Bruttopreis
    .PARAMETER netto                                                # Beschreibung des Parameters
    Angabe des Nettopreises
    .PARAMETER country                                              # Beschreibung des Parameters
    Angabe des Landes
    .LINK                                                           # Angabe des Links
    Spenden Sie an https://dasistmeinbruttonettorechner.de
    .EXAMPLE                                                        # Angabe eines Beispiels
    Get-Brutto -netto 1000 -country Deutschland
    #>
    [CmdletBinding(                                                 # Script unterstützt Globale Parameter
        ConfirmImpact="Medium",                                     # Verhalten wann "confirm"-Abfragen kommen sollen. Medium = weniger oft
        SupportsShouldProcess=$true                                 # Das Script unterstützt Globale "Confirm" und "WhatIf" Parameter
    )]
    param(                                                          # Get-Help about_Functions_Advanced_Parameters ... zeigt alle
        [parameter(Mandatory = $true, Position=0)]                  # Mandatory = Parameter muss gesetzt sein
                                                                    # Position = Parameter muss an erster Stelle kommen
        [ValidateRange(0,1000000000000)]                            # ValidateRange = von 0 bis 1000000000000
        [alias("netprice","n")]                                     # Setzt einen Alias für den Parameter (Kürzel)
        [double]$netto,

        [ValidateSet("Deutschland", "Russland", "Luxenburg")]       # Gibt Auswahlmöglichkeiten vor
        [alias("country","c","l")]                                  # Setzt einen Alias für den Parameter (Kürzel)
        [parameter(Position=1)]
        [string]$country = "Deutschland"
    )
    $Write-Debug "Haltepunkt 1 - bei Funktionsstart"                # Debug Haltepunkt (1) setzten (wird angezeigt wenn -debug verwendet wird)
    switch($country){
        "Deutschland"   {$tax = 0.19}
        "Russland"      {$tax = 0.21}
        "Luxenburg"     {$tax = 0.07}
        #default        {$tax = 0.19}                               # Unnötig, da ValidateSet
    }
    $host.EnterNestedPromt()                                        # Enter Debug-Modus
    $brutto = $netto*(1+$tax)
    Write-Verbose "Nettopreis:   $netto"                            # Wird nur ausgegeben wenn der Parameter "-Verbose" verwendet wird
    Write-Verbose "Land:         $country"
    Write-Verbose "Umsatzsteuer: $tax"
    Write-Verbose "Bruttopreis:  $brutto"
    return $brutto                                                  # "return" gibt (Array)-Wert zurück und damit kann dann weitergerechnet werden
}

Get-Brutto -netto 1000 -country Deutschland -Verbose
