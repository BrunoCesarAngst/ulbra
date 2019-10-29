/*
 * Copyright (C) 2017 chcan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package controlador.editores;

import controlador.Editor;
import diagramas.logico.Campo;
import diagramas.logico.Constraint;
import diagramas.logico.DiagramaLogico;
import diagramas.logico.Tabela;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ItemEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 * @author chcan
 */
public class EditorDeIR extends javax.swing.JDialog {

    /**
     * Creates new form EditorDeCampos
     */
    public EditorDeIR(java.awt.Frame parent, boolean modal) {
        super(parent, modal);
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form. WARNING: Do NOT modify this code. The content of this method is always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        comboTabelas = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();
        chkIsnomeada = new javax.swing.JCheckBox();
        txtNome = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jToolBar1 = new javax.swing.JToolBar();
        Adicionar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        Principal = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        btnPronto = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        mostrador = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        java.util.ResourceBundle bundle = java.util.ResourceBundle.getBundle("principal/Formularios_pt_BR"); // NOI18N
        setTitle(bundle.getString("EditorDeCampos.title")); // NOI18N

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder(Editor.fromConfiguracao.getValor("Inspector.obj.constraint.key")));

        comboTabelas.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));
        comboTabelas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                comboTabelasActionPerformed(evt);
            }
        });

        jLabel1.setText(bundle.getString("EditorDeIR.Tabela.selecionada")); // NOI18N

        chkIsnomeada.setText(bundle.getString("EditorDeIR.nomeada")); // NOI18N

        txtNome.setText("jTextField1");

        jLabel2.setText(bundle.getString("EditorDeIR.lblIR.nome")); // NOI18N

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(comboTabelas, javax.swing.GroupLayout.PREFERRED_SIZE, 335, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(chkIsnomeada)
                        .addGap(28, 28, 28)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, 154, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(87, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 17, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(comboTabelas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(7, 7, 7)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(txtNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2)
                    .addComponent(chkIsnomeada))
                .addContainerGap())
        );

        jToolBar1.setFloatable(false);
        jToolBar1.setRollover(true);

        Adicionar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagens/mais.png"))); // NOI18N
        Adicionar.setText(bundle.getString("EditorDeIR.Adicionar.Campo")); // NOI18N
        Adicionar.setFocusable(false);
        Adicionar.setHorizontalTextPosition(javax.swing.SwingConstants.RIGHT);
        Adicionar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        Adicionar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AdicionarActionPerformed(evt);
            }
        });
        jToolBar1.add(Adicionar);

        Principal.setBackground(new java.awt.Color(204, 204, 204));
        Principal.setLayout(null);
        jScrollPane1.setViewportView(Principal);

        jPanel2.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        btnPronto.setText(bundle.getString("EditorDeCampos.Fechar")); // NOI18N
        btnPronto.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnProntoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnPronto)
                .addGap(2, 2, 2))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addGap(0, 0, 0)
                .addComponent(btnPronto))
        );

        mostrador.setEditable(false);
        mostrador.setColumns(20);
        mostrador.setRows(5);
        jScrollPane2.setViewportView(mostrador);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jToolBar1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane2)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.TRAILING)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, 0)
                .addComponent(jToolBar1, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(1, 1, 1)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 174, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnProntoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnProntoActionPerformed
        DoneTexto();
        this.setVisible(false);
    }//GEN-LAST:event_btnProntoActionPerformed

    int v = 0;

    private void AdicionarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AdicionarActionPerformed
        Campo c = getSelecionada().Add(Editor.fromConfiguracao.getValor("diagrama.Campo.nome"));
        AdicionarPainel(c);
        getSelecionada().DoMuda();
    }//GEN-LAST:event_AdicionarActionPerformed

    private void comboTabelasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_comboTabelasActionPerformed
    }//GEN-LAST:event_comboTabelasActionPerformed

    private void Done() {
        Constraint pk = getSelecionada().getConstraints().stream().filter(c -> c.getTipo() == Constraint.CONSTRAINT_TIPO.tpPK).findAny().orElse(null);
        if (pk == null) {
            chkIsnomeada.setSelected(false);
            txtNome.setText("");
            txtNome.setEnabled(false);
            return;
        }
        chkIsnomeada.setSelected(pk.isNomeada());
        txtNome.setEnabled(pk.isNomeada());
        txtNome.setText(pk.getNome());
        mostrador.setText(pk.getDDL());
    }

    private void DoneTexto() {
        Constraint pk = getSelecionada().getConstraints().stream().filter(c -> c.getTipo() == Constraint.CONSTRAINT_TIPO.tpPK).findAny().orElse(null);
        if (pk == null) {
            chkIsnomeada.setSelected(false);
            txtNome.setText("");
            txtNome.setEnabled(false);
            mostrador.setText("");
            return;
        }
        if (pk.isNomeada() != chkIsnomeada.isSelected() || !pk.getNome().equals(txtNome.getText())) {
            pk.setNomeada(chkIsnomeada.isSelected());
            pk.setNome(txtNome.getText());
            getSelecionada().DoMuda();
        }
        txtNome.setEnabled(pk.isNomeada());
        txtNome.setText(pk.getNome());
        mostrador.setText(pk.getDDL());
    }

    public class InternalItem {

        javax.swing.JCheckBox chUnique = new javax.swing.JCheckBox();
        javax.swing.JCheckBox chkfk = new javax.swing.JCheckBox();
        javax.swing.JButton btnExcluirCampo = new javax.swing.JButton();
        Campo campo = null;
    }

    ArrayList<InternalItem> Itens = new ArrayList<>();

    private int largura = 0;
    
    public void AdicionarPainel(Campo cmp) {
        java.util.ResourceBundle bundle = java.util.ResourceBundle.getBundle("principal/Formularios_pt_BR");

        InternalItem item = new InternalItem();
        Itens.add(item);
        item.campo = cmp;

        javax.swing.JLabel lblTipo = new javax.swing.JLabel();
        javax.swing.JCheckBox chkCampo = new javax.swing.JCheckBox();
        javax.swing.JCheckBox chUnique = item.chUnique;
        javax.swing.JCheckBox chkfk = item.chkfk;
        javax.swing.JButton btnExcluir = item.btnExcluirCampo;
        javax.swing.JComboBox<String> comboTipo = new javax.swing.JComboBox<>();


        javax.swing.JPanel ItemPan = new javax.swing.JPanel();
        final int altura = 37;

        ItemPan.setSize(largura, altura);
        java.awt.FlowLayout lay = new java.awt.FlowLayout(java.awt.FlowLayout.LEFT, 10, 5);
        ItemPan.setLayout(lay);

        chkCampo.setText(cmp.getTexto());
        chkCampo.setPreferredSize(new Dimension(120, 23));
        ItemPan.add(chkCampo);

        lblTipo.setText(bundle.getString("EditorDeCampos.lblTipo")); // NOI18N
        lblTipo.setSize(new Dimension(24, 14));
        ItemPan.add(lblTipo);

        comboTipo.setEditable(true);
        String tipo_txt = cmp.getTipo();
        if (!tipo_txt.trim().isEmpty() && tipos.indexOf(tipo_txt) < 0) {
            tipos.add(tipo_txt);
        }
        comboTipo.setModel(new javax.swing.DefaultComboBoxModel(tipos.toArray()));
        comboTipo.setSelectedItem(tipo_txt);
        comboTipo.setPreferredSize(new Dimension(73, 20));
        ItemPan.add(comboTipo);

        chkfk.setText(bundle.getString("EditorDeIR.chkFK")); // NOI18N
        chkfk.setSize(new Dimension(115, 23));
        ItemPan.add(chkfk);

        chUnique.setText(bundle.getString("EditorDeIR.chkUNIQUE")); // NOI18N
        chUnique.setSize(new Dimension(51, 23));
        ItemPan.add(chUnique);

        btnExcluir.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagens/excluir.png"))); // NOI18N
        btnExcluir.setToolTipText(bundle.getString("EditorDeCampos.tooltip.excluir")); // NOI18N
        btnExcluir.setPreferredSize(new Dimension(49, 25));
        ItemPan.add(btnExcluir);

        Principal.add(ItemPan);
        if (largura == 0) {
            largura = lay.preferredLayoutSize(ItemPan).width;
        }
        ItemPan.setBounds(0, v, largura, altura);
        v += altura + 3;
        Principal.setPreferredSize(new Dimension(largura, v));

        chkCampo.setSelected(cmp.isKey());
        chkfk.setSelected(cmp.isFkey());
        chUnique.setSelected(cmp.isUnique());
        //chUnique.setEnabled(false);
        chUnique.setToolTipText(Editor.fromConfiguracao.getValor("Inspector.dica.campo.unique"));
        
        chkfk.addItemListener((java.awt.event.ItemEvent evt) -> {
            if (populando) {
                return;
            }
            if (cmp.isFkey() != chkfk.isSelected()) {
                cmp.setFkey(chkfk.isSelected());
                cmp.getTabela().DoMuda();
                cmp.InvalidateArea();
                Done();
            }
        });

        chUnique.addItemListener((java.awt.event.ItemEvent evt) -> {
            if (populando) {
                return;
            }
            if (cmp.isUnique() != chUnique.isSelected()) {
                cmp.setUnique(chUnique.isSelected());
                cmp.getTabela().DoMuda();
                cmp.InvalidateArea();
                Done();
            }
        });

        chkCampo.addItemListener((java.awt.event.ItemEvent evt) -> {
            if (populando) {
                return;
            }
            if (cmp.isKey() != chkCampo.isSelected()) {
                cmp.setKey(chkCampo.isSelected());
                Constraint pk = getSelecionada().getConstraints().stream().filter(c -> c.getTipo() == Constraint.CONSTRAINT_TIPO.tpPK).findAny().orElse(null);
                if (pk != null) {
                    getSelecionada().setConstraintSelecionado(pk);
                }
                cmp.getTabela().DoMuda();
                cmp.InvalidateArea();
                Done();
            }
        });

        btnExcluir.addActionListener((java.awt.event.ActionEvent evt) -> {
            cmp.getTabela().RemoveCampo(cmp);
            ItemPan.setEnabled(false);
            chkCampo.setEnabled(false);
            chUnique.setEnabled(false);
            chkfk.setEnabled(false);
            btnExcluir.setEnabled(false);
            comboTipo.setEnabled(false);
            ItemPan.setBackground(Color.lightGray);
            Done();
        });
        
        
        comboTipo.addActionListener((ActionEvent e) -> {
            String txt = comboTipo.getSelectedItem().toString();
            if (!txt.equals(cmp.getTipo())) {
                cmp.setTipo(txt);
                cmp.getTabela().DoMuda();
                cmp.InvalidateArea();
                if (tipos.indexOf(txt) < 0) {
                    tipos.add(0, txt);
                }
            }
        });

        comboTipo.getEditor().addActionListener((ActionEvent e) -> {
            String txt = comboTipo.getSelectedItem().toString();
            if (!txt.equals(cmp.getTipo())) {
                cmp.setTipo(txt);
                cmp.getTabela().DoMuda();
                cmp.InvalidateArea();
                if (tipos.indexOf(txt) < 0) {
                    tipos.add(0, txt);
                }
            }
        });
        
        comboTipo.addPopupMenuListener(new javax.swing.event.PopupMenuListener() {
            @Override
            public void popupMenuCanceled(javax.swing.event.PopupMenuEvent evt) {
                comboTipo.setSelectedItem(cmp.getTipo());
            }

            @Override
            public void popupMenuWillBecomeInvisible(javax.swing.event.PopupMenuEvent evt) {
                comboTipo.setSelectedItem(cmp.getTipo());
            }

            @Override
            public void popupMenuWillBecomeVisible(javax.swing.event.PopupMenuEvent evt) {
                comboTipo.setModel(new javax.swing.DefaultComboBoxModel(tipos.toArray()));
            }
        });

        ItemPan.validate();
        Principal.validate();
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Adicionar;
    private javax.swing.JPanel Principal;
    private javax.swing.JButton btnPronto;
    private javax.swing.JCheckBox chkIsnomeada;
    private javax.swing.JComboBox<String> comboTabelas;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JTextArea mostrador;
    private javax.swing.JTextField txtNome;
    // End of variables declaration//GEN-END:variables

    DiagramaLogico diagrama = null;
    List<Tabela> tabelas = null;
    ArrayList<String> tipos = new ArrayList<>();
    
    public void Inicie(DiagramaLogico diag) {
        diagrama = diag;
        comboTabelas.removeAllItems();
        tabelas = diagrama.getListaDeTabelas();
        Tabela sel = (diag.getSelecionado() instanceof Tabela ? (Tabela) diag.getSelecionado() : null);
        int idx = 0;
        for (int i = 0; i < tabelas.size(); i++) {
            Tabela t = tabelas.get(i);
            comboTabelas.addItem(String.valueOf(i + 1) + " - " + t.getTexto());
            if (t == sel) {
                idx = i;
            }
        }
        tipos.addAll(diag.getDataModel().getDataTypes());
        
        sel = tabelas.get(idx);

        comboTabelas.setSelectedIndex(idx);

        comboTabelas.addItemListener((ItemEvent e) -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                setSelecionada(tabelas.get(comboTabelas.getSelectedIndex()));
            }
        });
        setSelecionada(sel);

        txtNome.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {
            }

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                    Constraint pk = getSelecionada().getConstraints().stream().filter(c -> c.getTipo() == Constraint.CONSTRAINT_TIPO.tpPK).findAny().orElse(null);
                    if (pk == null) {
                        return;
                    }
                    txtNome.setText(pk.getNome());
                } else if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    DoneTexto();
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {
            }
        });

        chkIsnomeada.addItemListener((java.awt.event.ItemEvent evt) -> {
            if (populando) {
                return;
            }
            DoneTexto();
        });

        chkIsnomeada.addActionListener((java.awt.event.ActionEvent evt) -> {
            if (populando) {
                return;
            }
            DoneTexto();
        });
        
    }

    private Tabela selecionada = null;

    public Tabela getSelecionada() {
        return selecionada;
    }

    public void setSelecionada(Tabela selecionada) {
        if (this.selecionada != selecionada) {
            this.selecionada = selecionada;
            Popule(selecionada);
        }
    }

    private boolean populando = false;

    private void Popule(Tabela sel) {
        populando = true;
        Principal.removeAll();
        Principal.validate();
        Itens.clear();
        v = 0;
        sel.getCampos().stream().forEach(c -> AdicionarPainel(c));
        Principal.repaint();
        Done();
        populando = false;
    }
}
