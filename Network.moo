<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{09F85137-3BBA-4710-A23E-B3BE4FBE0029}" Label="" LastModificationDate="1383076790" Name="Diagramme de classes_1" Objects="112" Symbols="22" Target="Analyse" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>09F85137-3BBA-4710-A23E-B3BE4FBE0029</a:ObjectID>
<a:Name>Diagramme de classes_1</a:Name>
<a:Code>Diagramme_de_classes_1</a:Code>
<a:CreationDate>1382428597</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516878</a:ModificationDate>
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
<a:ObjectID>235078D1-9EA3-4E51-AA98-9683BA1F6E04</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382428594</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382428594</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>87317290-AF03-469F-BC1E-99593F18A4AB</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:ClassDiagrams>
<o:ClassDiagram Id="o4">
<a:ObjectID>231D5014-9671-4EE0-9B67-1E956D2235FC</a:ObjectID>
<a:Name>DiagrammeClasses_1</a:Name>
<a:Code>DiagrammeClasses_1</a:Code>
<a:CreationDate>1382428597</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516878</a:ModificationDate>
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
<o:GeneralizationSymbol Id="o5">
<a:CreationDate>1382516294</a:CreationDate>
<a:ModificationDate>1382516989</a:ModificationDate>
<a:Rect>((-1781,8052), (16223,28493))</a:Rect>
<a:ListOfPoints>((-1781,8052),(16223,8052),(16223,28493))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o8"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o9">
<a:CreationDate>1382516591</a:CreationDate>
<a:ModificationDate>1382517045</a:ModificationDate>
<a:Rect>((18203,14578), (40568,25163))</a:Rect>
<a:ListOfPoints>((40568,21435),(40568,14578),(18203,14578),(18203,25163))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o11"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o12">
<a:CreationDate>1382516661</a:CreationDate>
<a:ModificationDate>1382517008</a:ModificationDate>
<a:Rect>((-12661,-13788), (-7406,7394))</a:Rect>
<a:ListOfPoints>((-12661,-13788),(-12661,-2539),(-7406,-2539),(-7406,7394))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o6"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o14"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o15">
<a:CreationDate>1382516833</a:CreationDate>
<a:ModificationDate>1382517003</a:ModificationDate>
<a:Rect>((2889,-4501), (8630,7611))</a:Rect>
<a:ListOfPoints>((8630,-4501),(8630,2222),(2889,2222),(2889,7611))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o16"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o6"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o17"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o18">
<a:CreationDate>1382516844</a:CreationDate>
<a:ModificationDate>1382517011</a:ModificationDate>
<a:Rect>((-546,-27347), (7676,-13478))</a:Rect>
<a:ListOfPoints>((7676,-27347),(7676,-23478),(-546,-23478),(-546,-13478))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o13"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o20"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o21">
<a:CreationDate>1382516845</a:CreationDate>
<a:ModificationDate>1382517013</a:ModificationDate>
<a:Rect>((7024,-27407), (12004,-2348))</a:Rect>
<a:ListOfPoints>((8636,-27407),(8636,-17321),(10393,-17321),(10393,-2348))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o19"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o16"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o22"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o23">
<a:CreationDate>1382516865</a:CreationDate>
<a:ModificationDate>1382517034</a:ModificationDate>
<a:Rect>((53639,-25598), (60936,-3184))</a:Rect>
<a:ListOfPoints>((60936,-25598),(60936,-16339),(53639,-16339),(53639,-3184))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o24"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o25"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o26"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o27">
<a:CreationDate>1382516865</a:CreationDate>
<a:ModificationDate>1382517051</a:ModificationDate>
<a:Rect>((60110,-25658), (65090,5844))</a:Rect>
<a:ListOfPoints>((61896,-25658),(61896,-10434),(63305,-10434),(63305,5844))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o24"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o28"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o29"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o30">
<a:CreationDate>1382516877</a:CreationDate>
<a:ModificationDate>1382517045</a:ModificationDate>
<a:Rect>((36602,-2776), (37602,19744))</a:Rect>
<a:ListOfPoints>((37114,-2776),(37114,1049),(37090,1049),(37090,19744))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o25"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o10"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o31"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o32">
<a:CreationDate>1382516878</a:CreationDate>
<a:ModificationDate>1382517051</a:ModificationDate>
<a:Rect>((49823,8693), (56420,19083))</a:Rect>
<a:ListOfPoints>((49823,8693),(49823,14307),(56420,14307),(56420,19083))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o28"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o10"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o33"/>
</c:Object>
</o:GeneralizationSymbol>
<o:ClassSymbol Id="o34">
<a:CreationDate>1382515692</a:CreationDate>
<a:ModificationDate>1382517047</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((60586,20346), (75518,27153))</a:Rect>
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
<o:Class Ref="o35"/>
</c:Object>
</o:ClassSymbol>
<o:InterfaceSymbol Id="o7">
<a:CreationDate>1382515780</a:CreationDate>
<a:ModificationDate>1382516971</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((8590,24626), (20494,33264))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>10263757</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Interface Ref="o36"/>
</c:Object>
</o:InterfaceSymbol>
<o:ClassSymbol Id="o6">
<a:CreationDate>1382516045</a:CreationDate>
<a:ModificationDate>1382516989</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-10148,5351), (9420,11198))</a:Rect>
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
<o:Class Ref="o37"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o38">
<a:CreationDate>1382516055</a:CreationDate>
<a:ModificationDate>1382516973</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-21000,22504), (606,31080))</a:Rect>
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
<o:ClassSymbol Id="o40">
<a:CreationDate>1382516185</a:CreationDate>
<a:ModificationDate>1382516974</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-19989,13262), (-9959,18000))</a:Rect>
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
<o:ClassSymbol Id="o10">
<a:CreationDate>1382516458</a:CreationDate>
<a:ModificationDate>1382517045</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((33979,17671), (58923,23518))</a:Rect>
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
<o:ClassSymbol Id="o13">
<a:CreationDate>1382516631</a:CreationDate>
<a:ModificationDate>1382516992</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-19842,-18844), (6028,-11228))</a:Rect>
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
<o:ClassSymbol Id="o16">
<a:CreationDate>1382516632</a:CreationDate>
<a:ModificationDate>1382516990</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-5927,-8526), (19944,-908))</a:Rect>
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
<o:ClassSymbol Id="o19">
<a:CreationDate>1382516836</a:CreationDate>
<a:ModificationDate>1382517011</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((5877,-29897), (10676,-26118))</a:Rect>
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
<o:ClassSymbol Id="o25">
<a:CreationDate>1382516865</a:CreationDate>
<a:ModificationDate>1382516980</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((30331,-8550), (61579,-934))</a:Rect>
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
<o:ClassSymbol Id="o28">
<a:CreationDate>1382516865</a:CreationDate>
<a:ModificationDate>1382517051</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((42895,3499), (74143,11117))</a:Rect>
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
<o:ClassSymbol Id="o24">
<a:CreationDate>1382516865</a:CreationDate>
<a:ModificationDate>1382517034</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((59137,-28149), (63937,-24369))</a:Rect>
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
<o:Class Id="o35">
<a:ObjectID>6F8A3EAE-A9E6-43ED-94A4-6D2CA2E48E47</a:ObjectID>
<a:Name>SocketPool</a:Name>
<a:Code>SocketPool</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515692</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Singleton</a:Stereotype>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o49">
<a:ObjectID>32C7DB8E-ADAB-409E-A63D-CBF50128701C</a:ObjectID>
<a:Name>_sockets</a:Name>
<a:Code>_sockets</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515766</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::list&lt;ISocket*&gt;</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o50">
<a:ObjectID>C7442A03-791D-4E81-986E-90B1E1CE0DEB</a:ObjectID>
<a:Name>_watcher</a:Name>
<a:Code>_watcher</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515692</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>Thread</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o51">
<a:ObjectID>E0F60BB7-A94F-451B-B502-A7A5E813229F</a:ObjectID>
<a:Name>watchSocket</a:Name>
<a:Code>watchSocket</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515692</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o52">
<a:ObjectID>2E776D73-2091-43AD-8D7C-50781E4523DD</a:ObjectID>
<a:Name>sock</a:Name>
<a:Code>sock</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515759</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>ISocket *</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o53">
<a:ObjectID>47FAC8D2-6765-4FB2-B180-E00F542CD599</a:ObjectID>
<a:Name>releaseSocket</a:Name>
<a:Code>releaseSocket</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515692</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o54">
<a:ObjectID>5317A0E7-6ADE-46CD-AA38-AFACB240F5BF</a:ObjectID>
<a:Name>sock</a:Name>
<a:Code>sock</a:Code>
<a:CreationDate>1382515692</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382515765</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>ISocket*</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o37">
<a:ObjectID>23008039-6773-46E9-9FC6-7C22CBB3D443</a:ObjectID>
<a:Name>ATCPSock</a:Name>
<a:Code>ATCPSock</a:Code>
<a:CreationDate>1382516045</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516698</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Attributes>
<o:Attribute Id="o55">
<a:ObjectID>5CC5724B-8757-486B-83CF-B1EC9D7D03D3</a:ObjectID>
<a:Name>_buff</a:Name>
<a:Code>_buff</a:Code>
<a:CreationDate>1382516241</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516616</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>IOBuff</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
<c:ObjectDataType>
<o:Class Ref="o41"/>
</c:ObjectDataType>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o56">
<a:ObjectID>845C060C-9C19-4C72-A752-F2DFDB36CA36</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516296</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516730</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o57">
<a:ObjectID>3B708805-66AF-4812-B3E6-A067B914B25E</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516324</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516341</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o58">
<a:ObjectID>AF1DEF80-2EAA-403E-835D-F683D9A6A811</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516324</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516341</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o59">
<a:ObjectID>F211615A-B181-4299-A430-FEE5677EFF01</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516390</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516730</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>unsigned int</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o60">
<a:ObjectID>C7A0D59F-6DF7-42CD-A76D-153DE2E5FF56</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516390</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516402</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o61">
<a:ObjectID>496E3945-EE77-4E02-BECD-259F18A07362</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516390</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516402</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o39">
<a:ObjectID>5E94085D-1996-45EC-BBF7-7F56E725E7BF</a:ObjectID>
<a:Name>CircularBuffer</a:Name>
<a:Code>CircularBuffer</a:Code>
<a:CreationDate>1382516055</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516437</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o62">
<a:ObjectID>6AA77CA4-CF53-4450-81E8-9AF1FD8978F4</a:ObjectID>
<a:Name>_buff</a:Name>
<a:Code>_buff</a:Code>
<a:CreationDate>1382516122</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516152</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>char *</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o63">
<a:ObjectID>1233B91A-2EE5-41F6-AA88-EA9E23A2D292</a:ObjectID>
<a:Name>_idx</a:Name>
<a:Code>_idx</a:Code>
<a:CreationDate>1382516122</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516152</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>unsigned int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o64">
<a:ObjectID>3D0BF5A0-59D0-47B1-80B4-C5133A4FC20B</a:ObjectID>
<a:Name>_size</a:Name>
<a:Code>_size</a:Code>
<a:CreationDate>1382516122</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516152</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>unsigned int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o65">
<a:ObjectID>6C73E82F-8B01-4278-9CE6-0E17C163C359</a:ObjectID>
<a:Name>CircularBuffer</a:Name>
<a:Code>CircularBuffer</a:Code>
<a:CreationDate>1382516152</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516177</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o66">
<a:ObjectID>B36336DC-7BDB-4243-9AB6-9976B6B40BD0</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516166</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516177</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o67">
<a:ObjectID>C0D85B07-8D97-4499-B26A-57D3C8545249</a:ObjectID>
<a:Name>readSome</a:Name>
<a:Code>readSome</a:Code>
<a:CreationDate>1382516056</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516114</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o68">
<a:ObjectID>1BB69003-C085-4176-B60A-91D7845CE005</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516084</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516114</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o69">
<a:ObjectID>A4347FC6-1218-431A-AC59-178085DBE81E</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516084</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516114</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o70">
<a:ObjectID>FBB997F1-B111-4103-B73B-49FF8164EB09</a:ObjectID>
<a:Name>writeSome</a:Name>
<a:Code>writeSome</a:Code>
<a:CreationDate>1382516056</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516118</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o71">
<a:ObjectID>ACBB1A71-412C-41F4-A758-5E13639A658E</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516115</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516118</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o72">
<a:ObjectID>CD5CAC0D-FD04-4C7C-8596-DA11873A9742</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516115</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516118</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o73">
<a:ObjectID>B37C5995-F733-4662-9B66-0E14EBDA7B12</a:ObjectID>
<a:Name>readableSize</a:Name>
<a:Code>readableSize</a:Code>
<a:CreationDate>1382516416</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516437</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o41">
<a:ObjectID>31BD8C5A-F10D-44D7-A71B-6DAA27BF438F</a:ObjectID>
<a:Name>IOBuff</a:Name>
<a:Code>IOBuff</a:Code>
<a:CreationDate>1382516185</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516258</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o74">
<a:ObjectID>293EEF5A-9257-4F0C-BA30-A749D62F30DE</a:ObjectID>
<a:Name>input</a:Name>
<a:Code>input</a:Code>
<a:CreationDate>1382516186</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516210</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>CircularBuffer</a:DataType>
<c:ObjectDataType>
<o:Class Ref="o39"/>
</c:ObjectDataType>
</o:Attribute>
<o:Attribute Id="o75">
<a:ObjectID>97814816-0720-4692-9A30-09BB8E8C604D</a:ObjectID>
<a:Name>output</a:Name>
<a:Code>output</a:Code>
<a:CreationDate>1382516186</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516210</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>CircularBuffer</a:DataType>
<c:ObjectDataType>
<o:Class Ref="o39"/>
</c:ObjectDataType>
</o:Attribute>
</c:Attributes>
</o:Class>
<o:Class Id="o42">
<a:ObjectID>0DB3B259-49EC-47EA-AB60-A70A9E06C1BE</a:ObjectID>
<a:Name>AUDPSock</a:Name>
<a:Code>AUDPSock</a:Code>
<a:CreationDate>1382516458</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516539</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Attributes>
<o:Attribute Id="o76">
<a:ObjectID>68DB5188-33F6-4224-B779-12D852156784</a:ObjectID>
<a:Name>_hosts</a:Name>
<a:Code>_hosts</a:Code>
<a:CreationDate>1382516479</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516611</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>std::map&lt;IN_ADDR, IOBuff&gt;</a:DataType>
<a:Attribute.Visibility>#</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o77">
<a:ObjectID>FC566C51-2BC2-4CC5-9811-91C462D3865F</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516551</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o78">
<a:ObjectID>8B051D25-EA8A-49FD-99B5-729BD42630E3</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516539</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o79">
<a:ObjectID>A7903E24-5AD1-45FE-8857-40EF538D380E</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516539</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o80">
<a:ObjectID>68819D68-F3BB-4746-AE39-5B1BEF107C60</a:ObjectID>
<a:Name>to</a:Name>
<a:Code>to</a:Code>
<a:CreationDate>1382516539</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516551</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o81">
<a:ObjectID>D7711490-31C2-4DD0-9C77-4948F6BB732C</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516562</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>unsigned int</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o82">
<a:ObjectID>E17A96F9-36C7-4439-BB35-51A13C03E976</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516539</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o83">
<a:ObjectID>C55E6492-1C94-4B0F-A03B-D531F03C187B</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516535</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516539</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o84">
<a:ObjectID>DA58A00C-F3E5-4E1C-AC86-71C0474C3294</a:ObjectID>
<a:Name>from</a:Name>
<a:Code>from</a:Code>
<a:CreationDate>1382516552</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516562</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o43">
<a:ObjectID>CEF78D6A-5722-4563-9D26-381199A997E8</a:ObjectID>
<a:Name>CWTCPSocket</a:Name>
<a:Code>CWTCPSocket</a:Code>
<a:CreationDate>1382516631</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516852</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o85">
<a:ObjectID>5D560A91-4842-422E-9554-8CE43E5DBA30</a:ObjectID>
<a:Name>_sock</a:Name>
<a:Code>_sock</a:Code>
<a:CreationDate>1382516633</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516647</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>SOCKET</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o86">
<a:ObjectID>97CFFA7A-4855-4D10-860F-C846F0293EB6</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516793</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o87">
<a:ObjectID>EC22E3A5-56D8-4E46-A4D1-A0BB011D87CA</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516784</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o88">
<a:ObjectID>06CB3AF5-F299-4ECE-910E-8E21123CD60C</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516784</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o89">
<a:ObjectID>1A67CE98-0339-4853-8916-3365FD3E8C1B</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516799</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o90">
<a:ObjectID>2A8F93A4-2C26-4F1D-B778-000026C875BE</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516784</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o91">
<a:ObjectID>ECFEB238-2DD1-4886-AEB1-E422C553C983</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516775</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516784</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o92">
<a:ObjectID>068E6D1C-94F0-4A2D-86F0-0ADCC89B7F67</a:ObjectID>
<a:Name>getID</a:Name>
<a:Code>getID</a:Code>
<a:CreationDate>1382516742</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516755</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>SocketID</a:ReturnType>
</o:Operation>
<o:Operation Id="o93">
<a:ObjectID>069ED1F0-2141-499A-8AE7-35C7261200C4</a:ObjectID>
<a:Name>readFromSock</a:Name>
<a:Code>readFromSock</a:Code>
<a:CreationDate>1382516742</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516760</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
<o:Operation Id="o94">
<a:ObjectID>C2396831-8F1C-46E8-B3FB-B7673DFE9E13</a:ObjectID>
<a:Name>writeToSock</a:Name>
<a:Code>writeToSock</a:Code>
<a:CreationDate>1382516742</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516763</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o44">
<a:ObjectID>14F13DD6-38C9-479C-B056-3F4407CDE592</a:ObjectID>
<a:Name>CUTCPSocket</a:Name>
<a:Code>CUTCPSocket</a:Code>
<a:CreationDate>1382516632</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516857</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o95">
<a:ObjectID>D5FDEE32-5821-4E4F-898B-D3A1A289E6BC</a:ObjectID>
<a:Name>_sock</a:Name>
<a:Code>_sock</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o96">
<a:ObjectID>EE6834D8-F272-4BF2-B296-28C70E7A3C17</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o97">
<a:ObjectID>5E41A3F4-D779-459F-AE21-8A2A4D5845B5</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o98">
<a:ObjectID>9A566EFC-D92C-46AD-8AE1-96EB69171C2C</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o99">
<a:ObjectID>CA2AF707-BF9F-49AC-AAB6-C550F1C9428B</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o100">
<a:ObjectID>317EF4B3-096A-4AED-A331-9DA6B1062064</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o101">
<a:ObjectID>B05CAA51-38E6-4D29-924D-38F17DA4B57C</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o102">
<a:ObjectID>EB32544C-1655-4569-9740-FDE2EE64B804</a:ObjectID>
<a:Name>getID</a:Name>
<a:Code>getID</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>SocketID</a:ReturnType>
</o:Operation>
<o:Operation Id="o103">
<a:ObjectID>55D81F98-CE1A-44F6-975A-FA0B12B63CF6</a:ObjectID>
<a:Name>readFromSock</a:Name>
<a:Code>readFromSock</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
<o:Operation Id="o104">
<a:ObjectID>3F9EDE75-3271-4E8C-BAC9-2D9DF38E1431</a:ObjectID>
<a:Name>writeToSock</a:Name>
<a:Code>writeToSock</a:Code>
<a:CreationDate>1382516813</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516824</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o45">
<a:ObjectID>2E672E7D-3B70-45BF-9425-D469F4E05E15</a:ObjectID>
<a:Name>TCPSocket</a:Name>
<a:Code>TCPSocket</a:Code>
<a:CreationDate>1382516836</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516857</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
</o:Class>
<o:Class Id="o46">
<a:ObjectID>1A7277A1-DFF7-4E84-A12D-54F1B8472ABB</a:ObjectID>
<a:Name>CWUDPSocket</a:Name>
<a:Code>CWUDPSocket</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516886</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o105">
<a:ObjectID>024DF5B0-2E29-47A7-910A-7387952A1247</a:ObjectID>
<a:Name>_sock</a:Name>
<a:Code>_sock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>SOCKET</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o106">
<a:ObjectID>AC729FED-390C-4D74-AD31-B35B7F2BD9E0</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516896</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o107">
<a:ObjectID>E19CFA24-D4BA-478E-966B-83D04CB795F3</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o108">
<a:ObjectID>179E85C7-84FB-436A-B1F5-F405F71E8A52</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o109">
<a:ObjectID>00D909A2-0424-44B2-A1D9-F353053DEFC4</a:ObjectID>
<a:Name>to</a:Name>
<a:Code>to</a:Code>
<a:CreationDate>1382516888</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516896</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o110">
<a:ObjectID>49DCE422-DDA8-437E-972C-2324664F4714</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516908</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o111">
<a:ObjectID>61D00580-2C4D-49C6-B7E6-567D5C03A1AD</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o112">
<a:ObjectID>DE90F87F-F59C-4310-80C0-96DAD344F1E2</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o113">
<a:ObjectID>059D0405-AC04-4E91-AD5C-517B1E0E5077</a:ObjectID>
<a:Name>from</a:Name>
<a:Code>from</a:Code>
<a:CreationDate>1382516899</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516908</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o114">
<a:ObjectID>73646D9D-F911-429E-88DF-3A9CE533BFB6</a:ObjectID>
<a:Name>getID</a:Name>
<a:Code>getID</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>SocketID</a:ReturnType>
</o:Operation>
<o:Operation Id="o115">
<a:ObjectID>65903A4D-60F2-4073-A206-1E3D4660F2E1</a:ObjectID>
<a:Name>readFromSock</a:Name>
<a:Code>readFromSock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
<o:Operation Id="o116">
<a:ObjectID>15BD5C4A-DC28-4F3A-80E1-55984A50BFDD</a:ObjectID>
<a:Name>writeToSock</a:Name>
<a:Code>writeToSock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o47">
<a:ObjectID>2EB91956-4358-4778-B032-508094410D70</a:ObjectID>
<a:Name>CUUDPSocket</a:Name>
<a:Code>CUUDPSocket</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516954</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o117">
<a:ObjectID>05E448AD-D844-480C-981A-32CFCF605431</a:ObjectID>
<a:Name>_sock</a:Name>
<a:Code>_sock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>int</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o118">
<a:ObjectID>8574D948-C00A-413A-935D-B5BF2D54C8AC</a:ObjectID>
<a:Name>send</a:Name>
<a:Code>send</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516943</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o119">
<a:ObjectID>485A8F72-455D-43E8-8CE5-DBD7612BE92D</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o120">
<a:ObjectID>A911FF48-3356-45C7-A626-0CA2E7097CBD</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o121">
<a:ObjectID>186B17CD-F50E-4E84-8EBC-D4CB95E56307</a:ObjectID>
<a:Name>to</a:Name>
<a:Code>to</a:Code>
<a:CreationDate>1382516935</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516943</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o122">
<a:ObjectID>50F94E44-DDB9-4FAB-9307-B1EE1529BBBC</a:ObjectID>
<a:Name>recv</a:Name>
<a:Code>recv</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516953</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>unsigned int</a:ReturnType>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o123">
<a:ObjectID>33042601-0477-466C-BDFF-580BF4CF1D86</a:ObjectID>
<a:Name>buff</a:Name>
<a:Code>buff</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>char *</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o124">
<a:ObjectID>A982E59D-0CF8-43B8-A54E-BC984D525C84</a:ObjectID>
<a:Name>size</a:Name>
<a:Code>size</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o125">
<a:ObjectID>DDD45BA2-8C98-42C8-A1D1-2A4D832D0207</a:ObjectID>
<a:Name>from</a:Name>
<a:Code>from</a:Code>
<a:CreationDate>1382516944</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516953</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>IN_ADDR</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o126">
<a:ObjectID>24A23258-3BDC-458E-8C7F-BEA6DBCBEA80</a:ObjectID>
<a:Name>getID</a:Name>
<a:Code>getID</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>SocketID</a:ReturnType>
</o:Operation>
<o:Operation Id="o127">
<a:ObjectID>6AA1314D-4B68-4149-9AAE-C3BF596FF2E6</a:ObjectID>
<a:Name>readFromSock</a:Name>
<a:Code>readFromSock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
<o:Operation Id="o128">
<a:ObjectID>3E6E2FEB-D17E-4BB9-9B39-59EBE610FB9A</a:ObjectID>
<a:Name>writeToSock</a:Name>
<a:Code>writeToSock</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o48">
<a:ObjectID>33E1AB87-A3B7-4974-AE15-584F74EE6CBD</a:ObjectID>
<a:Name>UDPSocket</a:Name>
<a:Code>UDPSocket</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516959</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
</o:Class>
</c:Classes>
<c:Interfaces>
<o:Interface Id="o36">
<a:ObjectID>C744D524-E463-4514-BFD7-718B475C67DE</a:ObjectID>
<a:Name>ISocket</a:Name>
<a:Code>ISocket</a:Code>
<a:CreationDate>1382515780</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1383076790</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Operations>
<o:Operation Id="o129">
<a:ObjectID>276F6438-0CB1-4D33-8948-2EF6BEF9B89B</a:ObjectID>
<a:Name>getID</a:Name>
<a:Code>getID</a:Code>
<a:CreationDate>1382515781</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516698</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>SocketID</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o130">
<a:ObjectID>BC4C86B3-E53A-4501-B72A-06EB9A9CBED0</a:ObjectID>
<a:Name>readFromSock</a:Name>
<a:Code>readFromSock</a:Code>
<a:CreationDate>1382515781</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516698</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o131">
<a:ObjectID>C3233646-1D2A-41F4-9E47-7A1AFF0034D4</a:ObjectID>
<a:Name>writeToSock</a:Name>
<a:Code>writeToSock</a:Code>
<a:CreationDate>1382515781</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516698</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o132">
<a:ObjectID>3494DD60-D6EA-445D-9B27-89DEDD6180E1</a:ObjectID>
<a:Name>setAccept</a:Name>
<a:Code>setAccept</a:Code>
<a:CreationDate>1383076104</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1383076173</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o133">
<a:ObjectID>889EEBC1-7314-46AC-BC24-7E1CC15CFB49</a:ObjectID>
<a:Name>canAccept</a:Name>
<a:Code>canAccept</a:Code>
<a:CreationDate>1383076162</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1383076173</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o134">
<a:ObjectID>F03E90B9-D93B-47DA-A853-E6A9CCDD718A</a:ObjectID>
<a:Name>wantToWrite</a:Name>
<a:Code>wantToWrite</a:Code>
<a:CreationDate>1383076782</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1383076790</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
</c:Operations>
</o:Interface>
</c:Interfaces>
<c:Generalizations>
<o:Generalization Id="o14">
<a:ObjectID>9B4402BF-6B06-42BC-BD46-0CCF5E92816A</a:ObjectID>
<a:Name>Generalisation_1</a:Name>
<a:Code>Generalisation_1</a:Code>
<a:CreationDate>1382516661</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516661</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o37"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o43"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o17">
<a:ObjectID>B2DDC7F1-F726-4C7B-821D-2CC82C612660</a:ObjectID>
<a:Name>Generalisation_2</a:Name>
<a:Code>Generalisation_2</a:Code>
<a:CreationDate>1382516833</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516833</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o37"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o44"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o20">
<a:ObjectID>804B63A9-22F7-4F56-8787-2DFF2914D25C</a:ObjectID>
<a:Name>Generalisation_3</a:Name>
<a:Code>Generalisation_3</a:Code>
<a:CreationDate>1382516844</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516852</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si windows</a:Stereotype>
<c:Object1>
<o:Class Ref="o43"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o45"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o22">
<a:ObjectID>64D3632D-7DF8-4E03-AC27-B52487D42B5C</a:ObjectID>
<a:Name>Generalisation_4</a:Name>
<a:Code>Generalisation_4</a:Code>
<a:CreationDate>1382516845</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516857</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si unix</a:Stereotype>
<c:Object1>
<o:Class Ref="o44"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o45"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o26">
<a:ObjectID>7EF6D54F-C732-48E8-88F9-FBBCA58815CB</a:ObjectID>
<a:Name>Generalisation_3</a:Name>
<a:Code>Generalisation_3</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si windows</a:Stereotype>
<c:Object1>
<o:Class Ref="o46"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o48"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o29">
<a:ObjectID>165950D1-1BE8-400C-A067-3E21D78ED924</a:ObjectID>
<a:Name>Generalisation_4</a:Name>
<a:Code>Generalisation_4</a:Code>
<a:CreationDate>1382516865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si unix</a:Stereotype>
<c:Object1>
<o:Class Ref="o47"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o48"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o31">
<a:ObjectID>7232BAA7-1D3E-4BFD-A586-228CBF89EB7C</a:ObjectID>
<a:Name>Generalisation_7</a:Name>
<a:Code>Generalisation_7</a:Code>
<a:CreationDate>1382516877</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516877</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o42"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o46"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o33">
<a:ObjectID>78DEE364-A7BA-4187-85D6-033A40E44261</a:ObjectID>
<a:Name>Generalisation_8</a:Name>
<a:Code>Generalisation_8</a:Code>
<a:CreationDate>1382516878</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516878</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Class Ref="o42"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o47"/>
</c:Object2>
</o:Generalization>
</c:Generalizations>
<c:Realizations>
<o:Realization Id="o8">
<a:ObjectID>B7DB99BC-1C49-4599-8453-E8461BE09982</a:ObjectID>
<a:Name>Realisation_1</a:Name>
<a:Code>Realisation_1</a:Code>
<a:CreationDate>1382516294</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516294</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Interface Ref="o36"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o37"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o11">
<a:ObjectID>42D5A666-D1CD-448C-A1CF-DDEE014E98F9</a:ObjectID>
<a:Name>Realisation_2</a:Name>
<a:Code>Realisation_2</a:Code>
<a:CreationDate>1382516591</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382516591</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<c:Object1>
<o:Interface Ref="o36"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o42"/>
</c:Object2>
</o:Realization>
</c:Realizations>
<c:TargetModels>
<o:TargetModel Id="o135">
<a:ObjectID>2AF49998-28B6-480B-AC69-04232C2DE265</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382428594</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382428594</a:ModificationDate>
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