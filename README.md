# ono_repository
アクションゲーム作成用のリポジトリ

# DxLibの構築手順
1. まずは下記のサイトからDxLibをダウンロードしてください。  
[DXライブラリのダウンロード](https://dxlib.xsrv.jp/dxdload.html)

2. ダウンロードが終わったら下記のサイトに従って構築していきます。  
[DXライブラリの構築手順](https://dxlib.xsrv.jp/dxuse.html)

# 環境変数の登録
1. 上記でダウンロードしたDxLibを任意の場所で解凍する。

2. Windowsシステムツールを開いて、システムとセキュリティからシステムを開く。

3. システムの詳細設定 -> 環境変数の順に選択していく。

4. システム環境変数の新規を選択し、変数名にDxLibと記載し、ディレクトリの参照を押して、(DxLibを解凍した場所)\DxLib_VC3_22a\DxLib_VC\プロジェクトに追加すべきファイル_VC用を選択してOKを押す。

   上記の工程を経た後、プロジェクトを開いてビルドが正常に通ればOK。

# 実装内容
## 操作方法
* エンターキーでシーン移動
* 十字キー左右で移動
* スペースキーでジャンプ
* Rキーで座標リセット

