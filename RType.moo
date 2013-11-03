<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{52F55444-CC2F-4690-B850-1F9F54AEADB2}" Label="" LastModificationDate="1382513613" Name="Diagramme de classes_1" Objects="85" Symbols="24" Target="Analyse" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>52F55444-CC2F-4690-B850-1F9F54AEADB2</a:ObjectID>
<a:Name>Diagramme de classes_1</a:Name>
<a:Code>Diagramme_de_classes_1</a:Code>
<a:CreationDate>1382440446</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513449</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:PackageOptionsText>[FolderOptions]

[FolderOptions\Class Diagram Objects]
GenerationCheckModel=Yes
GenerationPath=
GenerationOptions=
GenerationTasks=
GenerationTargets=
GenerationSelections=</a:PackageOptionsText>
<a:ModelOptionsText>[ModelOptions]

[ModelOptions\Cld]
CaseSensitive=No
DisplayName=Yes
EnableTrans=No
EnableRequirements=No
ShowClss=No
DeftAttr=int
DeftMthd=
DeftParm=int
DeftCont=
DomnDttp=Yes
DomnChck=No
DomnRule=No
SupportDelay=No
PreviewEditable=Yes
AutoRealize=No
DttpFullName=Yes
DeftClssAttrVisi=private
VBNetPreprocessingSymbols=
CSharpPreprocessingSymbols=

[ModelOptions\Cld\NamingOptionsTemplates]

[ModelOptions\Cld\ClssNamingOptions]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN]

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS]

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF]

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR]

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS]

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT]

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG]

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP]

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR]

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD]

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM]

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT]

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART]

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC]

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC]

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK]

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK]

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK]

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK]

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV]

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST]

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT]

[ModelOptions\Cld\ClssNamingOptions\STAT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE]

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI]

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC]

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR]

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO]

[ModelOptions\Cld\ClssNamingOptions\FILO\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=&quot;\/:*?&lt;&gt;|&quot;
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_. &quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ]

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK]

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass]

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Generate]

[ModelOptions\Generate\Cdm]
CheckModel=Yes
SaveLinks=Yes
NameToCode=No
Notation=2

[ModelOptions\Generate\Pdm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No
BuildTrgr=No
TablePrefix=
RefrUpdRule=RESTRICT
RefrDelRule=RESTRICT
IndxPKName=%TABLE%_PK
IndxAKName=%TABLE%_AK
IndxFKName=%REFR%_FK
IndxThreshold=
ColnFKName=%.3:PARENT%_%COLUMN%
ColnFKNameUse=No

[ModelOptions\Generate\Xsm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No</a:ModelOptionsText>
<c:ObjectLanguage>
<o:Shortcut Id="o3">
<a:ObjectID>9F5F2ED3-9BB3-4342-AAA6-8FA45C40590B</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382440446</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440446</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>87317290-AF03-469F-BC1E-99593F18A4AB</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:ClassDiagrams>
<o:ClassDiagram Id="o4">
<a:ObjectID>E0F8FE4E-91D6-4D78-9443-65E340296ECF</a:ObjectID>
<a:Name>DiagrammeClasses_1</a:Name>
<a:Code>DiagrammeClasses_1</a:Code>
<a:CreationDate>1382440446</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513449</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\CLD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=No
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=0
Trunc Length=80
Word Length=80
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Class.IconPicture=No
Class_SymbolLayout=
Interface.IconPicture=No
Interface_SymbolLayout=
Port.IconPicture=No
Port_SymbolLayout=
ClssShowSttr=Yes
Class.Comment=No
ClssShowCntr=Yes
ClssShowAttr=Yes
ClssAttrTrun=No
ClssAttrMax=3
ClssShowMthd=Yes
ClssMthdTrun=No
ClssMthdMax=3
ClssShowInnr=Yes
IntfShowSttr=Yes
Interface.Comment=No
IntfShowAttr=Yes
IntfAttrTrun=No
IntfAttrMax=3
IntfShowMthd=Yes
IntfMthdTrun=No
IntfMthdMax=3
IntfShowCntr=Yes
IntfShowInnr=Yes
PortShowName=Yes
PortShowType=No
PortShowMult=No
AttrShowVisi=Yes
AttrVisiFmt=1
AttrShowStrn=Yes
AttrShowDttp=Yes
AttrShowDomn=No
AttrShowInit=Yes
MthdShowVisi=Yes
MthdVisiFmt=1
MthdShowStrn=Yes
MthdShowRttp=Yes
MthdShowParm=Yes
AsscShowName=No
AsscShowCntr=Yes
AsscShowRole=Yes
AsscShowOrdr=Yes
AsscShowMult=Yes
AsscMultStr=Yes
AsscShowStrn=No
GnrlShowName=No
GnrlShowStrn=Yes
GnrlShowCntr=Yes
RlzsShowName=No
RlzsShowStrn=Yes
RlzsShowCntr=Yes
DepdShowName=No
DepdShowStrn=Yes
DepdShowCntr=Yes
RqlkShowName=No
RqlkShowStrn=Yes
RqlkShowCntr=Yes

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=No
Width=2400
Height=2400
Brush color=255 255 255
Fill Color=No
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=-1

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDCLASS]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
ClassPrimaryAttributeFont=Arial,8,U
ClassPrimaryAttributeFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=233 202 131
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDINTF]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=205 156 156
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMPORT]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
AutoAdjustToText=No
Keep aspect=No
Keep center=No
Keep size=No
Width=825
Height=800
Brush color=250 241 211
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDASSC]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
MULAFont=Arial,8,N
MULAFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\INNERLINK]
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDACLK]
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\GNRLLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RLZSLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=3 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RQLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\DEPDLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8500, 11000)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>259</a:PaperSource>
<c:Symbols>
<o:AssociationSymbol Id="o5">
<a:CreationDate>1382441864</a:CreationDate>
<a:ModificationDate>1382513613</a:ModificationDate>
<a:Rect>((6120,9120), (24295,26768))</a:Rect>
<a:ListOfPoints>((22195,26768),(22195,19080),(8220,19080),(8220,9120))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o8"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o9">
<a:CreationDate>1382441965</a:CreationDate>
<a:ModificationDate>1382513551</a:ModificationDate>
<a:Rect>((1217,16200), (9843,30125))</a:Rect>
<a:ListOfPoints>((8065,30125),(7800,21840),(3197,21840),(3197,16200))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3336</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o10"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o11"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o12">
<a:CreationDate>1382442063</a:CreationDate>
<a:ModificationDate>1382513602</a:ModificationDate>
<a:SourceTextOffset>(-30, -1840)</a:SourceTextOffset>
<a:Rect>((-14082,3580), (-8095,14440))</a:Rect>
<a:ListOfPoints>((-8095,14440),(-11982,14440),(-11982,3580))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3336</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o13"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o14"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o15">
<a:CreationDate>1382443514</a:CreationDate>
<a:ModificationDate>1382513595</a:ModificationDate>
<a:Rect>((-15108,19965), (2883,24212))</a:Rect>
<a:ListOfPoints>((783,24212),(783,19965),(-15108,19965))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3336</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o16"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o17"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o18">
<a:CreationDate>1382443525</a:CreationDate>
<a:ModificationDate>1382513595</a:ModificationDate>
<a:Rect>((-21120,6240), (-12833,19965))</a:Rect>
<a:ListOfPoints>((-19020,6240),(-19020,11819),(-14933,11819),(-14933,19965))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o16"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o19"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o20">
<a:CreationDate>1382443752</a:CreationDate>
<a:ModificationDate>1382513523</a:ModificationDate>
<a:Rect>((2200,3070), (9960,14550))</a:Rect>
<a:ListOfPoints>((2940,14550),(2940,4230),(9960,4230))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o21"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o22"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o23">
<a:CreationDate>1382444659</a:CreationDate>
<a:ModificationDate>1382513523</a:ModificationDate>
<a:DestinationTextOffset>(-1994, -613)</a:DestinationTextOffset>
<a:Rect>((-3270,-420), (660,14340))</a:Rect>
<a:ListOfPoints>((-3270,14340),(-3270,6898),(660,6898),(660,-420))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o24"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o25"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o26">
<a:CreationDate>1382444991</a:CreationDate>
<a:ModificationDate>1382513504</a:ModificationDate>
<a:SourceTextOffset>(-1650, 200)</a:SourceTextOffset>
<a:Rect>((8340,-15450), (14369,-4752))</a:Rect>
<a:ListOfPoints>((14369,-4752),(14369,-9390),(10320,-9390),(10320,-15450))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o24"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o27"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o28"/>
</c:Object>
</o:AssociationSymbol>
<o:AssociationSymbol Id="o29">
<a:CreationDate>1382445102</a:CreationDate>
<a:ModificationDate>1382513531</a:ModificationDate>
<a:Rect>((6390,-23100), (15750,-17460))</a:Rect>
<a:ListOfPoints>((13650,-17460),(13650,-23100),(6390,-23100))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>3592</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N
MULA 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o27"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o30"/>
</c:DestinationSymbol>
<c:Object>
<o:Association Ref="o31"/>
</c:Object>
</o:AssociationSymbol>
<o:GeneralizationSymbol Id="o32">
<a:CreationDate>1382446634</a:CreationDate>
<a:ModificationDate>1382513529</a:ModificationDate>
<a:Rect>((-17217,-20900), (-9705,-328))</a:Rect>
<a:ListOfPoints>((-9705,-328),(-9705,-10191),(-17217,-10191),(-17217,-20900))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o33"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o34"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o35">
<a:CreationDate>1382446635</a:CreationDate>
<a:ModificationDate>1382513535</a:ModificationDate>
<a:Rect>((-13878,-25554), (6168,-20174))</a:Rect>
<a:ListOfPoints>((6168,-25554),(-13878,-25554),(-13878,-20174))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o30"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o33"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o36"/>
</c:Object>
</o:GeneralizationSymbol>
<o:ClassSymbol Id="o37">
<a:CreationDate>1382440466</a:CreationDate>
<a:ModificationDate>1382513590</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-22232,22608), (-2850,32294))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o38"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o6">
<a:CreationDate>1382440988</a:CreationDate>
<a:ModificationDate>1382513551</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-1856,23371), (23088,30987))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o39"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o7">
<a:CreationDate>1382441607</a:CreationDate>
<a:ModificationDate>1382513613</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((6171,9032), (21907,13770))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o40"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o10">
<a:CreationDate>1382441890</a:CreationDate>
<a:ModificationDate>1382513523</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-9313,13410), (4631,17189))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o41"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o13">
<a:CreationDate>1382442016</a:CreationDate>
<a:ModificationDate>1382513500</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-23350,-2249), (-7368,6329))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o42"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o16">
<a:CreationDate>1382442416</a:CreationDate>
<a:ModificationDate>1382513595</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-22280,17309), (-11322,21087))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o43"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o21">
<a:CreationDate>1382443636</a:CreationDate>
<a:ModificationDate>1382513474</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((5500,2489), (22822,7227))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o44"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o24">
<a:CreationDate>1382444562</a:CreationDate>
<a:ModificationDate>1382513502</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((260,-6270), (16902,386))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o45"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o27">
<a:CreationDate>1382444763</a:CreationDate>
<a:ModificationDate>1382513504</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((9345,-18209), (20177,-12512))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o46"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o30">
<a:CreationDate>1382445003</a:CreationDate>
<a:ModificationDate>1382513531</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((4130,-27628), (11832,-21932))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o47"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o33">
<a:CreationDate>1382445968</a:CreationDate>
<a:ModificationDate>1382513529</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-20117,-21192), (-10252,-17415))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o48"/>
</c:Object>
</o:ClassSymbol>
</c:Symbols>
</o:ClassDiagram>
</c:ClassDiagrams>
<c:DefaultDiagram>
<o:ClassDiagram Ref="o4"/>
</c:DefaultDiagram>
<c:Classes>
<o:Class Id="o38">
<a:ObjectID>DF7CA525-5A59-4397-97AA-00FA7B09153E</a:ObjectID>
<a:Name>Debug</a:Name>
<a:Code>Debug</a:Code>
<a:CreationDate>1382440466</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440750</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>singletone</a:Stereotype>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o49">
<a:ObjectID>0C791E2D-B218-4A9C-9169-55F051689197</a:ObjectID>
<a:Name>_errorLvl</a:Name>
<a:Code>_errorLvl</a:Code>
<a:CreationDate>1382440467</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440536</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>ELvlError</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o50">
<a:ObjectID>8B6BA0C1-106B-410D-A824-A156B88B9329</a:ObjectID>
<a:Name>_outputStream</a:Name>
<a:Code>_outputStream</a:Code>
<a:CreationDate>1382440513</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440803</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::ofstream</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o51">
<a:ObjectID>AF511B90-2BA4-4F9A-AA48-34A38D409CA8</a:ObjectID>
<a:Name>debug</a:Name>
<a:Code>debug</a:Code>
<a:CreationDate>1382440560</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440615</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Debug</a:DataType>
<a:Static>1</a:Static>
<c:ObjectDataType>
<o:Class Ref="o38"/>
</c:ObjectDataType>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o52">
<a:ObjectID>85C3A632-3A97-4760-ACAE-A932B5578A52</a:ObjectID>
<a:Name>log</a:Name>
<a:Code>log</a:Code>
<a:CreationDate>1382440618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440682</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o53">
<a:ObjectID>AD08CE77-C582-4043-96C7-CB25F1C81853</a:ObjectID>
<a:Name>msg</a:Name>
<a:Code>msg</a:Code>
<a:CreationDate>1382440647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440682</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o54">
<a:ObjectID>547743C0-2F72-43B1-8C07-1CB371E4EF62</a:ObjectID>
<a:Name>lvlError</a:Name>
<a:Code>lvlError</a:Code>
<a:CreationDate>1382440647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440682</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>ELvlError</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o55">
<a:ObjectID>B302CA22-9365-4786-A6EF-D55A6DF1DA52</a:ObjectID>
<a:Name>setLvlError</a:Name>
<a:Code>setLvlError</a:Code>
<a:CreationDate>1382440647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440714</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o56">
<a:ObjectID>72FBD30B-D901-49F4-A346-969A5836F145</a:ObjectID>
<a:Name>lvlError</a:Name>
<a:Code>lvlError</a:Code>
<a:CreationDate>1382440694</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440714</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>ELvlError</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o57">
<a:ObjectID>166D56F1-909C-4485-A1CE-B07310896415</a:ObjectID>
<a:Name>getLvlError</a:Name>
<a:Code>getLvlError</a:Code>
<a:CreationDate>1382440694</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440750</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>ELvlError</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o58">
<a:ObjectID>BDA53974-0CB8-4A39-B90A-A466FAEBB6ED</a:ObjectID>
<a:Name>setLogFile</a:Name>
<a:Code>setLogFile</a:Code>
<a:CreationDate>1382440694</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440765</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o59">
<a:ObjectID>B7291843-2978-45F8-9E92-4928F0E2C6E1</a:ObjectID>
<a:Name>filename</a:Name>
<a:Code>filename</a:Code>
<a:CreationDate>1382440750</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440765</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o39">
<a:ObjectID>1EAA7B1A-C052-4459-B691-916AE52F2F7E</a:ObjectID>
<a:Name>RTypeServer</a:Name>
<a:Code>RTypeServer</a:Code>
<a:CreationDate>1382440988</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444685</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o60">
<a:ObjectID>51CF2B6F-3249-4310-9690-C91D5EF9C33F</a:ObjectID>
<a:Name>_port</a:Name>
<a:Code>_port</a:Code>
<a:CreationDate>1382440990</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441110</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o61">
<a:ObjectID>B83EF92C-F4D8-4AC1-8000-7082A4545A01</a:ObjectID>
<a:Name>_maxRoom</a:Name>
<a:Code>_maxRoom</a:Code>
<a:CreationDate>1382440990</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441110</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o62">
<a:ObjectID>D55DB8A5-545C-46B5-BA98-B02E14D9718C</a:ObjectID>
<a:Name>_blFile</a:Name>
<a:Code>_blFile</a:Code>
<a:CreationDate>1382440990</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441110</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::ofstream</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o63">
<a:ObjectID>D5B8C00D-4820-4C51-8E7E-27B434933D10</a:ObjectID>
<a:Name>start</a:Name>
<a:Code>start</a:Code>
<a:CreationDate>1382441110</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441132</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o64">
<a:ObjectID>AA7668F6-607F-46BB-BEBB-5D209A137C46</a:ObjectID>
<a:Name>RTypeServer</a:Name>
<a:Code>RTypeServer</a:Code>
<a:CreationDate>1382441147</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441225</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o65">
<a:ObjectID>497A96BF-396C-4427-B225-DAB213D5154C</a:ObjectID>
<a:Name>port</a:Name>
<a:Code>port</a:Code>
<a:CreationDate>1382441157</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441236</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DefaultValue>1234</a:DefaultValue>
<a:Parameter.DataType>int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o66">
<a:ObjectID>29426DC5-1C10-499F-8B34-68237BCD7BE0</a:ObjectID>
<a:Name>maxRoom</a:Name>
<a:Code>maxRoom</a:Code>
<a:CreationDate>1382441157</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441293</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DefaultValue>20</a:DefaultValue>
<a:Parameter.DataType>int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o67">
<a:ObjectID>D8C6DBB0-BCC7-43E2-82E9-C3EB7B0510EA</a:ObjectID>
<a:Name>blPath</a:Name>
<a:Code>blPath</a:Code>
<a:CreationDate>1382441157</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513579</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DefaultValue>.bl</a:DefaultValue>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o68">
<a:ObjectID>A98382FC-C663-4B2E-98AF-B4FC278DCD8E</a:ObjectID>
<a:Name>loadDynEnnemy</a:Name>
<a:Code>loadDynEnnemy</a:Code>
<a:CreationDate>1382443804</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443834</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o69">
<a:ObjectID>579BCFA9-F391-425E-911B-A0583F07BB7A</a:ObjectID>
<a:Name>filename</a:Name>
<a:Code>filename</a:Code>
<a:CreationDate>1382443819</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443834</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o40">
<a:ObjectID>18E0924F-1A89-4B8B-9DB1-4CE851C6733D</a:ObjectID>
<a:Name>Prompt</a:Name>
<a:Code>Prompt</a:Code>
<a:CreationDate>1382441607</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513456</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o70">
<a:ObjectID>5AD3CF98-3DD0-4E57-ACC0-3E16656454A2</a:ObjectID>
<a:Name>_th</a:Name>
<a:Code>_th</a:Code>
<a:CreationDate>1382513450</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513456</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Thread</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o71">
<a:ObjectID>5C36EA09-DBB2-4D3B-B9E7-2149AF364625</a:ObjectID>
<a:Name>interpretLine</a:Name>
<a:Code>interpretLine</a:Code>
<a:CreationDate>1382441608</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441654</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o72">
<a:ObjectID>1CED2BD1-4483-4F87-9DA2-764A42534FB9</a:ObjectID>
<a:Name>line</a:Name>
<a:Code>line</a:Code>
<a:CreationDate>1382441642</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441654</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o73">
<a:ObjectID>8269746D-57BB-4F7E-824C-D513F017E939</a:ObjectID>
<a:Name>interpretFile</a:Name>
<a:Code>interpretFile</a:Code>
<a:CreationDate>1382441608</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441689</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o74">
<a:ObjectID>9399D22F-57C9-4B03-8C2E-742E6BB8B9AC</a:ObjectID>
<a:Name>filename</a:Name>
<a:Code>filename</a:Code>
<a:CreationDate>1382441667</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441678</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o41">
<a:ObjectID>A38A925E-9028-4693-8563-B774DC823490</a:ObjectID>
<a:Name>Room</a:Name>
<a:Code>Room</a:Code>
<a:CreationDate>1382441890</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382447720</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o75">
<a:ObjectID>B7658DE9-CCA4-4D7F-B9F2-DC5598B4EE53</a:ObjectID>
<a:Name>_th</a:Name>
<a:Code>_th</a:Code>
<a:CreationDate>1382447703</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382513449</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Thread</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o76">
<a:ObjectID>936521F9-0C61-46C8-B201-5B384C93BBF3</a:ObjectID>
<a:Name>addPlayer</a:Name>
<a:Code>addPlayer</a:Code>
<a:CreationDate>1382443550</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443583</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o77">
<a:ObjectID>F8AC749C-CF58-4D1D-88FC-68D3DC3AF7C3</a:ObjectID>
<a:Name>client</a:Name>
<a:Code>client</a:Code>
<a:CreationDate>1382443576</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443583</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Client</a:Parameter.DataType>
<c:ObjectDataType>
<o:Class Ref="o43"/>
</c:ObjectDataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o42">
<a:ObjectID>7B6C8834-D9D7-4105-8632-A0E47FE4DDC1</a:ObjectID>
<a:Name>Player</a:Name>
<a:Code>Player</a:Code>
<a:CreationDate>1382442016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443534</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o78">
<a:ObjectID>0BB5EDED-D77A-4548-BED7-4003BBDD49F2</a:ObjectID>
<a:Name>_name</a:Name>
<a:Code>_name</a:Code>
<a:CreationDate>1382442016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442054</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::string</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o79">
<a:ObjectID>BEF0A120-9DA3-46F4-84E2-BC1448C3C33B</a:ObjectID>
<a:Name>_id</a:Name>
<a:Code>_id</a:Code>
<a:CreationDate>1382442016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442054</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o80">
<a:ObjectID>5E7A0D1D-6245-4001-BC91-9F53DF082AAA</a:ObjectID>
<a:Name>_ready</a:Name>
<a:Code>_ready</a:Code>
<a:CreationDate>1382442016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442054</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>boolean</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o81">
<a:ObjectID>A80F8250-258C-4556-829F-F77CD1C99FED</a:ObjectID>
<a:Name>_pos</a:Name>
<a:Code>_pos</a:Code>
<a:CreationDate>1382442016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442054</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>float[2]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o82">
<a:ObjectID>56B0CF26-746C-4A69-A502-E3EC1B9E893C</a:ObjectID>
<a:Name>_tcpSock</a:Name>
<a:Code>_tcpSock</a:Code>
<a:CreationDate>1382442128</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442155</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>TCPSocket</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o83">
<a:ObjectID>19C4D668-567F-4F1B-B073-003FEDF3A38C</a:ObjectID>
<a:Name>_udpSock</a:Name>
<a:Code>_udpSock</a:Code>
<a:CreationDate>1382442128</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442155</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>UDPSocket</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o84">
<a:ObjectID>CADD48F7-D250-4C10-AED0-2FD96857C6CB</a:ObjectID>
<a:Name>sendFile</a:Name>
<a:Code>sendFile</a:Code>
<a:CreationDate>1382442217</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442251</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o85">
<a:ObjectID>131C5626-4A5C-4AB6-8225-5F6A46A1AC7C</a:ObjectID>
<a:Name>filename</a:Name>
<a:Code>filename</a:Code>
<a:CreationDate>1382442237</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442251</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o43">
<a:ObjectID>AD158310-2571-409A-AB74-6CF8AB12AFEC</a:ObjectID>
<a:Name>Client</a:Name>
<a:Code>Client</a:Code>
<a:CreationDate>1382442416</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382448559</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o86">
<a:ObjectID>D211A223-DC39-4AFD-BB9E-A1756BE6178B</a:ObjectID>
<a:Name>_tcpSocket</a:Name>
<a:Code>_tcpSocket</a:Code>
<a:CreationDate>1382442417</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443338</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>TCPSocket</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
</o:Class>
<o:Class Id="o44">
<a:ObjectID>5EA23E4D-D314-471C-9D63-6D593746C26F</a:ObjectID>
<a:Name>Script</a:Name>
<a:Code>Script</a:Code>
<a:CreationDate>1382443636</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444675</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o87">
<a:ObjectID>F53BB798-B218-4CED-98DD-6EDA65C32F13</a:ObjectID>
<a:Name>Script</a:Name>
<a:Code>Script</a:Code>
<a:CreationDate>1382443724</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443727</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Constructor</a:Stereotype>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Class Ref="o44"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o88">
<a:ObjectID>6A44EF62-6BCD-4537-B533-591C5EC95D93</a:ObjectID>
<a:Name>Script</a:Name>
<a:Code>Script</a:Code>
<a:CreationDate>1382443683</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443722</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o89">
<a:ObjectID>358C2618-9917-419E-AE4A-8CD830B58F86</a:ObjectID>
<a:Name>script</a:Name>
<a:Code>script</a:Code>
<a:CreationDate>1382443692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443722</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>std::string</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o45">
<a:ObjectID>3EF18FBF-49CC-4EDD-84FC-73B74697D769</a:ObjectID>
<a:Name>Game</a:Name>
<a:Code>Game</a:Code>
<a:CreationDate>1382444562</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445898</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o90">
<a:ObjectID>44D82E2C-D7EF-49CB-8400-D055FD024120</a:ObjectID>
<a:Name>_players</a:Name>
<a:Code>_players</a:Code>
<a:CreationDate>1382444563</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444655</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Player[4]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o91">
<a:ObjectID>4F602587-C48C-44F1-8BCD-594D57B5AE02</a:ObjectID>
<a:Name>_script</a:Name>
<a:Code>_script</a:Code>
<a:CreationDate>1382444563</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444655</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Script</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
<c:ObjectDataType>
<o:Class Ref="o44"/>
</c:ObjectDataType>
</o:Attribute>
<o:Attribute Id="o92">
<a:ObjectID>65E24610-1A2F-4408-AADB-BD9190A0C05C</a:ObjectID>
<a:Name>_livingThings</a:Name>
<a:Code>_livingThings</a:Code>
<a:CreationDate>1382445390</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445819</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::list&lt;Element&gt;[18][16]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o93">
<a:ObjectID>713220A0-6C00-4293-A7ED-B2FD81684ADA</a:ObjectID>
<a:Name>_map</a:Name>
<a:Code>_map</a:Code>
<a:CreationDate>1382445888</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445898</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>char[]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
<a:Multiplicity>*</a:Multiplicity>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o94">
<a:ObjectID>7F708A41-821E-4438-BC1B-2E920EF25103</a:ObjectID>
<a:Name>gameLoop</a:Name>
<a:Code>gameLoop</a:Code>
<a:CreationDate>1382445173</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445181</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o46">
<a:ObjectID>9EC18FBC-4F51-4B35-AE72-B87CDCF7DF8E</a:ObjectID>
<a:Name>AWave</a:Name>
<a:Code>AWave</a:Code>
<a:CreationDate>1382444763</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444976</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o95">
<a:ObjectID>E4A2DF53-9358-40FA-A41B-EC05C7DC1F34</a:ObjectID>
<a:Name>_livingMob</a:Name>
<a:Code>_livingMob</a:Code>
<a:CreationDate>1382444878</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444909</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>unsigned int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o96">
<a:ObjectID>3F2E6FAE-D2C9-4275-85D9-BB1641D22396</a:ObjectID>
<a:Name>start</a:Name>
<a:Code>start</a:Code>
<a:CreationDate>1382444909</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444976</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o97">
<a:ObjectID>0F9E3DC9-F2AD-41D3-9137-AAA624B6D677</a:ObjectID>
<a:Name>moveMobs</a:Name>
<a:Code>moveMobs</a:Code>
<a:CreationDate>1382444909</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444976</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o98">
<a:ObjectID>F0DE7E2B-2E2D-437C-AF66-9FFFB392A9D1</a:ObjectID>
<a:Name>mobsAction</a:Name>
<a:Code>mobsAction</a:Code>
<a:CreationDate>1382444909</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444976</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o47">
<a:ObjectID>8CB07227-D7FB-4B50-B4FA-6F495373073C</a:ObjectID>
<a:Name>Ennemy</a:Name>
<a:Code>Ennemy</a:Code>
<a:CreationDate>1382445003</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445092</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o99">
<a:ObjectID>505E46BE-2BCC-4A72-BB84-3F1D7B25D988</a:ObjectID>
<a:Name>_hp</a:Name>
<a:Code>_hp</a:Code>
<a:CreationDate>1382445005</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445092</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o100">
<a:ObjectID>9471B10C-EE6F-4D6E-B1FE-07981DFBBA6B</a:ObjectID>
<a:Name>_pos</a:Name>
<a:Code>_pos</a:Code>
<a:CreationDate>1382445005</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445092</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>float[2]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o101">
<a:ObjectID>D5B5BEE7-DB41-4BBE-B52A-7FF6B19EFBCB</a:ObjectID>
<a:Name>reset</a:Name>
<a:Code>reset</a:Code>
<a:CreationDate>1382445005</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445092</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o102">
<a:ObjectID>02A817F2-F37E-47F6-BFC4-A19CABBEAC94</a:ObjectID>
<a:Name>onDeath</a:Name>
<a:Code>onDeath</a:Code>
<a:CreationDate>1382445005</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445092</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o48">
<a:ObjectID>28D6E10B-9C29-4029-808B-9850B97CEAE8</a:ObjectID>
<a:Name>Element</a:Name>
<a:Code>Element</a:Code>
<a:CreationDate>1382445968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446595</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o103">
<a:ObjectID>9DE7D176-1DCA-48B8-BD44-6D85508B18AA</a:ObjectID>
<a:Name>_pos</a:Name>
<a:Code>_pos</a:Code>
<a:CreationDate>1382446016</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446026</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>float[2]</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o104">
<a:ObjectID>3C84FF5F-9351-49A9-8F3C-E5B696733EAF</a:ObjectID>
<a:Name>move</a:Name>
<a:Code>move</a:Code>
<a:CreationDate>1382446026</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446608</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o105">
<a:ObjectID>092D8A1B-EFA4-4656-B856-351A5D84E78D</a:ObjectID>
<a:Name>v</a:Name>
<a:Code>v</a:Code>
<a:CreationDate>1382446595</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446608</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Vector2</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
</c:Classes>
<c:Associations>
<o:Association Id="o8">
<a:ObjectID>28B3E405-1B9E-44E5-B1D0-CA39FDAF8B43</a:ObjectID>
<a:Name>Association_1</a:Name>
<a:Code>Association_1</a:Code>
<a:CreationDate>1382441864</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441875</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>1..1</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o40"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o39"/>
</c:Object2>
</o:Association>
<o:Association Id="o11">
<a:ObjectID>B9335F54-9070-4884-BF6A-B80DFB319E00</a:ObjectID>
<a:Name>Association_2</a:Name>
<a:Code>Association_2</a:Code>
<a:CreationDate>1382441965</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444685</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>A</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o41"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o39"/>
</c:Object2>
</o:Association>
<o:Association Id="o14">
<a:ObjectID>24A2EDB0-02AE-4890-A297-711C8007AD99</a:ObjectID>
<a:Name>Association_3</a:Name>
<a:Code>Association_3</a:Code>
<a:CreationDate>1382442063</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382442072</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>A</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>1..4</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o42"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o41"/>
</c:Object2>
</o:Association>
<o:Association Id="o17">
<a:ObjectID>637145CB-EC4D-4FAE-98BB-D454CF23E565</a:ObjectID>
<a:Name>Association_4</a:Name>
<a:Code>Association_4</a:Code>
<a:CreationDate>1382443514</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443514</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>A</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o43"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o39"/>
</c:Object2>
</o:Association>
<o:Association Id="o19">
<a:ObjectID>264AD38F-8087-401E-BAED-F4557546C77F</a:ObjectID>
<a:Name>Association_5</a:Name>
<a:Code>Association_5</a:Code>
<a:CreationDate>1382443525</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382443534</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>1..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>1..1</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o43"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o42"/>
</c:Object2>
</o:Association>
<o:Association Id="o22">
<a:ObjectID>56C49C6B-2E14-4874-A8B5-14EB40D45EBA</a:ObjectID>
<a:Name>Association_6</a:Name>
<a:Code>Association_6</a:Code>
<a:CreationDate>1382443752</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444675</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>1..1</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o44"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o41"/>
</c:Object2>
</o:Association>
<o:Association Id="o25">
<a:ObjectID>F3520682-7BEF-4881-A27F-F7205DC31F74</a:ObjectID>
<a:Name>Association_7</a:Name>
<a:Code>Association_7</a:Code>
<a:CreationDate>1382444659</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444668</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>1..1</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o45"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o41"/>
</c:Object2>
</o:Association>
<o:Association Id="o28">
<a:ObjectID>DFC33FD1-FC54-4384-ABC4-17BFD73103D5</a:ObjectID>
<a:Name>Association_8</a:Name>
<a:Code>Association_8</a:Code>
<a:CreationDate>1382444991</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382444991</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o46"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o45"/>
</c:Object2>
</o:Association>
<o:Association Id="o31">
<a:ObjectID>8607EAD4-16CA-4397-A7B6-C31FE5F926D8</a:ObjectID>
<a:Name>Association_9</a:Name>
<a:Code>Association_9</a:Code>
<a:CreationDate>1382445102</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382445102</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:RoleAIndicator>C</a:RoleAIndicator>
<a:RoleAMultiplicity>0..1</a:RoleAMultiplicity>
<a:RoleBMultiplicity>0..*</a:RoleBMultiplicity>
<c:Object1>
<o:Class Ref="o47"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o46"/>
</c:Object2>
</o:Association>
</c:Associations>
<c:Generalizations>
<o:Generalization Id="o34">
<a:ObjectID>9B2ACAC4-4417-4E24-88FE-4F016E0A72BF</a:ObjectID>
<a:Name>Generalisation_2</a:Name>
<a:Code>Generalisation_2</a:Code>
<a:CreationDate>1382446634</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446634</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o48"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o42"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o36">
<a:ObjectID>331507C1-C725-4949-A625-4084970BF105</a:ObjectID>
<a:Name>Generalisation_3</a:Name>
<a:Code>Generalisation_3</a:Code>
<a:CreationDate>1382446635</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382446635</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o48"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o47"/>
</c:Object2>
</o:Generalization>
</c:Generalizations>
<c:TargetModels>
<o:TargetModel Id="o106">
<a:ObjectID>E1776F05-000C-403E-ABD0-7EB1DCD17618</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382440446</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440446</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TargetModelURL>file:///%_OBJLANG%/analysis.xol</a:TargetModelURL>
<a:TargetModelID>87317290-AF03-469F-BC1E-99593F18A4AB</a:TargetModelID>
<a:TargetModelClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetModelClassID>
<c:SessionShortcuts>
<o:Shortcut Ref="o3"/>
</c:SessionShortcuts>
</o:TargetModel>
</c:TargetModels>
</o:Model>
</c:Children>
</o:RootObject>

</Model>